#pragma once

#include <stddef.h>

/**
 * \brief Initializes the debug console for `printk` and `printk_hex`.
 * \param func This is a function with the signature `void(const char)` that can
 * be used to output a byte. This can be graphical or not, as long as it has
 * that signature.
 * \warning This function must be called before `printk` and `printk_hex`.
 */
void debug_setup(void(*)(const char));

/**
 * \brief Prints a string using the generic function provided to `debug_setup`.
 * \param s This is an unformatted C string. \r\n is not provided for serial.
 * \return The number of characters printed.
 */
int printk(const char*);

/**
 * \brief Prints a number using the generic function provided in hexadecimal
 * format. E.g, 15 is 0xF.
 * \param num The number to be printed.
 */
void printk_hex(size_t);
