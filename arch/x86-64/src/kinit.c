/*
This file is part of Seanix.

Seanix is free software: you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

Seanix is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with Seanix. If not, see <https://www.gnu.org/licenses/>.
*/

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
