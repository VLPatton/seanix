#pragma once

#include <stdint.h>

/**
 * \brief Post a byte to a given I/O port
 */
void outb(uint16_t, uint8_t);

/**
 * \brief Read a byte from a given I/O port
 */
uint8_t inb(uint16_t);
