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

#include "debug.h"
#include "string.h"
#include <stddef.h>

void (*putc_generic)(const char);

int printk(const char* str) {
    for (size_t i = 0; i < strlen(str); i++) {
        (*putc_generic)(str[i]);
    }
    return strlen(str);
}

void debug_setup(void (*func)(const char)) {
    putc_generic = func;
}

void debug_inplace_strrev(char* s, size_t begin, size_t end) {
    char c;

    if (begin >= end)
        return;

    c = s[begin];
    s[begin] = s[end];
    s[end] = c;

    debug_inplace_strrev(s, ++begin, --end);
}

void printk_hex(size_t num) {
    char arr[16] = "0123456789ABCDEF";

    char str[255];

    printk("0x");

    for (size_t i = 0; num > 0; i++) {
        str[i] = arr[num % 16];
        num /= 16;
    }
    debug_inplace_strrev(str, 0, strlen(str) - 1);
    printk(str);
}
