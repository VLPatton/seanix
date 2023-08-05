#include "cpu.h"

void outb(uint16_t port, uint8_t data) {
    asm volatile (
        "outb %0, %1"
        :
        : "a"(data), "Nd"(port)
        : "memory"
    );
}

uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile (
        "inb %1, %0"
        : "=a"(ret)
        : "Nd"(port)
        : "memory"
    );
    return ret;
}
