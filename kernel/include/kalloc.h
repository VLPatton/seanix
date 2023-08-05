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

