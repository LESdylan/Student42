#include "ft_printf.h"

/**
 * Writes a single character to the standard output.
 * @param args The variadic argument list containing the character.
 * @return The number of bytes written (1), or -1 on error.
 */
ssize_t ft_write_c(va_list args);

/**
 * Writes a null-terminated string to the standard output.
 * If the string is NULL, it writes "(null)" instead.
 * @param args The variadic argument list containing the string.
 * @return The number of bytes written, or -1 on error.
 */
ssize_t ft_write_str(va_list args);

/**
 * Writes a signed decimal integer to the standard output.
 * Handles negative numbers by writing a leading '-' sign.
 * @param args The variadic argument list containing the integer.
 * @return The number of bytes written, or -1 on error.
 */
ssize_t ft_write_dec(va_list args);

/**
 * Writes a signed integer to the standard output.
 * Identical in behavior to ft_write_dec since `%d` and `%i` are equivalent.
 * @param args The variadic argument list containing the integer.
 * @return The number of bytes written, or -1 on error.
 */
ssize_t ft_write_int(va_list args);

/**
 * Writes an unsigned integer to the standard output.
 * Does not handle negative values, as unsigned integers are always non-negative.
 * @param args The variadic argument list containing the unsigned integer.
 * @return The number of bytes written, or -1 on error.
 */
ssize_t ft_write_uns(va_list args);

/**
 * Writes a pointer address to the standard output in hexadecimal format.
 * Prefixes the output with "0x". If the pointer is NULL, writes "(nil)".
 * @param args The variadic argument list containing the pointer.
 * @return The number of bytes written, or -1 on error.
 */
ssize_t ft_write_ptr(va_list args);

/**
 * Writes an unsigned integer to the standard output in lowercase hexadecimal format.
 * @param args The variadic argument list containing the unsigned integer.
 * @return The number of bytes written, or -1 on error.
 */
ssize_t ft_write_hex_low(va_list args);

/**
 * Writes an unsigned integer to the standard output in uppercase hexadecimal format.
 * @param args The variadic argument list containing the unsigned integer.
 * @return The number of bytes written, or -1 on error.
 */
ssize_t ft_write_hex_cap(va_list args);

/**
 * Writes a literal '%' character to the standard output.
 * @param args The variadic argument list (not used for this function).
 * @return The number of bytes written (1), or -1 on error.
 */
ssize_t ft_write_percent(va_list args);
