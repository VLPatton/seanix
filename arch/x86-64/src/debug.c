
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
