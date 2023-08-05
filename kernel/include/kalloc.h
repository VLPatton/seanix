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
#include <stdint.h>

/**
 * \brief Sets up the kernel allocator using starting an ending pointers.
 * \param start The starting pointer.
 * \param end The ending pointer.
 * \warning `start` and `end` must point to a continuous block of free memory.
 */
void kalloc_setup(void*, void*);

