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
