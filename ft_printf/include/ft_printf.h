#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include "helpers.h"  // Décommente cette ligne

typedef ssize_t (*t_writer)(va_list args);
typedef struct s_format_map
{
    char specifier;
    t_writer writer;
} t_format_map;

ssize_t ft_write_c(va_list args);
ssize_t ft_write_str(va_list args);
ssize_t ft_write_dec(va_list args);
ssize_t ft_write_int(va_list args);
ssize_t ft_write_uns(va_list args);
ssize_t ft_write_ptr(va_list args);
ssize_t ft_write_hex_low(va_list args);
ssize_t ft_write_hex_cap(va_list args);
ssize_t ft_write_percent(va_list args);
int ft_printf(const char *fmt, ...);

#endif // FT_PRINTF_H
