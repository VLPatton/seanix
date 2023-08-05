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
 * \brief Copies each byte from `src` to `dest` for `n` bytes.
 * \param dest The destination pointer.
 * \param src The source pointer.
 * \param n The number of bytes to copy.
 * \return The destination pointer.
 */
void* memcpy(void*, const void*, size_t);

/**
 * \brief Sets each byte of `s` to `(uint8_t)c` for `n` bytes.
 * \param s The destination pointer.
 * \param c The byte to set everything to.
 * \param n The number of bytes to set.
 * \return The destination pointer.
 * \warning `c` is only copied as a `uint8_t` and not as an `int`.
 */
void* memset(void*, int, size_t);

/**
 * \brief Does a smarter `memcpy` that behaves differently if the pointers are
 * closer than `n` bytes to each other.
 * \param dest The destination pointer.
 * \param src The source pointer.
 * \param n The number of bytes to move.
 * \return The destination pointer.
 */
void* memmove(void*, const void*, size_t);

/**
 * \brief Compares to regions of memory, byte by byte, for `n` bytes.
 * \param a The first pointer.
 * \param b The second pointer.
 * \param n The number of bytes to compare.
 * \return -1 if `a < b`, 0 if `a == b`, and 1 if `a > b`.
 */
int memcmp(const void*, const void*, size_t);

/**
 * \brief Returns the length of a NUL-terminated C string.
 * \param str The string to measure.
 * \return The number of non-NUL bytes in the string.
 */
size_t strlen(const char*);
