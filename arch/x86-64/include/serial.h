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


/**
 * \brief Do basic setup of the serial port, preparing it for putc and getc.
 * \return 0 upon success.
 * \warning This must be called before calling `serial_getc` or `serial_putc`.
 * Undefined behavior is expected otherwise.
 */
int serial_setup(void);

/**
 * \brief Puts one char to the serial port, blocking if the serial tx buffer is
 * full.
 * \param c The character to put.
 */
void serial_putc(const char);

/**
 * \brief Gets one char from the serial port, block if the serial rx buffer is
 * empty.
 * \return The char given from the serial port.
 */
char serial_getc(void);
