#include "limine.h"
#include "alloc.h"
#include "kalloc.h"
#include "serial.h"
#include "debug.h"

volatile struct limine_memmap_request memmap_req = {
    .id = LIMINE_MEMMAP_REQUEST,
    .revision = 0
};

void _start(void) {
    serial_setup();
    debug_setup(&serial_putc);
    printk("Serial init complete\r\n");

    if (memmap_req.response == NULL)
        for(;;);
    uint64_t i = 0;
    for (; i < memmap_req.response->entry_count 
        && (memmap_req.response->entries[i]->type != LIMINE_MEMMAP_USABLE);
        i++
    );

    if (memmap_req.response->entries[i]->type == LIMINE_MEMMAP_USABLE) {
        void* start = (void*)memmap_req.response->entries[i]->base;
        void* end = start + memmap_req.response->entries[i]->length;
        kalloc_setup(start, end);
    }

    printk("kmalloc ready\r\n");



    for(;;);
}
