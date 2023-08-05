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

#include <stddef.h>
#include <stdint.h>
#include "alloc.h"
#include "kalloc.h"

#define USED 1
#define FREE 0
#define MAX_ALLOC (4096 * 8)

uint8_t frame_map[MAX_ALLOC];

void* start_available = NULL;
void* end_available = NULL;

void kalloc_setup(void* start, void* end) {
    start_available = start;
    end_available = end;
}

void* kalloc_page() {
    size_t i = 0;

    for (; frame_map[i] != FREE; i++) {
        if (i >= MAX_ALLOC)
            return NULL;
    }

    if (frame_map[i] == FREE)
        return (void*)(start_available + i*4096);
    else
        return NULL;
}

int is_range_free(size_t start, size_t n) {
    int is_free = 1;

    if (start + n > MAX_ALLOC)
        return !is_free;

    for (size_t i = 0; i < n; i++) {
        is_free = is_free && (frame_map[i + start] == FREE);
        if (!is_free)
            return is_free;
    }
    return is_free;
}

void* liballoc_alloc(size_t pages) {
    size_t i = 0;

    for (; !is_range_free(i, pages) && i + pages <= MAX_ALLOC; i++);

    if (is_range_free(i, pages)) {
        for (size_t j = 0; j < pages; j++) {
            frame_map[j] = USED;
        }
        return (void*)(start_available + i*4096);
    }

    return NULL;
}

int liballoc_free(void* addr, size_t n) {
    uintptr_t addr_uint = (uintptr_t)addr;
    if (addr_uint % 4096 != 0 || addr < start_available || addr > end_available)
        return -1;

    uintptr_t idx = (uintptr_t)(addr - start_available) / 4096;

    for (size_t i = 0; i < n; i++) {
        frame_map[idx + i] = FREE;
    }

    return 0;
}

int liballoc_lock() {
    return 0;
}

int liballoc_unlock() {
    return 0;
}
