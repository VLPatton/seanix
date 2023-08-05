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
