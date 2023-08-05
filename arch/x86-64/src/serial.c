#include "serial.h"
#include "cpu.h"

// COM1
#define PORT 0x03F8

int serial_setup() {
    outb(PORT + 1, 0x00);    // Disable all interrupts
    outb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
    outb(PORT + 0, 0x0C);    // Set divisor to 3 (lo byte) 38400 baud
    outb(PORT + 1, 0x00);    //                  (hi byte)
    outb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
    outb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
    outb(PORT + 4, 0x03);    // RTS/DSR set
    outb(PORT + 4, 0x1E);    // Set in loopback mode, test the serial chip
    outb(PORT + 0, 0xAE);    // Test serial chip (send byte 0xAE and check if serial returns same byte)

    // Check if serial is faulty (i.e: not same byte as sent)
    if(inb(PORT + 0) != 0xAE) {
        return 1;
    }

    // If serial is not faulty set it in normal operation mode
    // (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
    outb(PORT + 4, 0x03);
    return 0; 
}

int serial_has_received() {
    return inb(PORT + 5) & 1;
}

char serial_getc() {
    while (!serial_has_received());

    return inb(PORT);
}

int serial_is_tx_ready() {
    return inb(PORT + 5) & 0x20;
}

void serial_putc(const char c) {
    while (!serial_is_tx_ready());

    outb(PORT, c);
}
