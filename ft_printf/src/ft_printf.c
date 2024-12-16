/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:02:19 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 13:16:10 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Lookup and call the appropriate writer function based on the format specifier
ssize_t parse(const char *fmt, size_t *i, va_list args)
{
        // Format specifier lookup table
        const t_format_map formats[] = {
        {'c', ft_write_c},
        {'s', ft_write_str},
        {'d', ft_write_dec},
        {'i', ft_write_int},
        {'u', ft_write_uns},
        {'p', ft_write_ptr},
        {'x', ft_write_hex_low},
        {'X', ft_write_hex_cap},
        {'%', ft_write_percent},
        //'f', ft_write_float},  // Ajoute le format '%f'
        {0, NULL} // Fin de la table
    };
    char c = fmt[*i + 1];
    for (int j = 0; formats[j].specifier != 0; j++)
    {
        if (formats[j].specifier == c)
        {
            *i += 1; // Advance past the format specifier
            return formats[j].writer(args);
        }
    }

    // If the specifier is invalid, ignore and return 0
    return (0);
}

// Implementation of the ft_printf function
int ft_printf(const char *fmt, ...)
{
    va_list args;
    size_t i = 0;
    ssize_t count = 0;

    va_start(args, fmt);
    while (fmt[i])
    {
        if (fmt[i] == '%' && fmt[i + 1]) // Check for format specifier
        {
            ssize_t res = parse(fmt, &i, args);
            if (res < 0) // Handle error (if needed)
                return -1;
            count += res;
        }
        else
        {
            write(1, &fmt[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return count;
}

// Lookup table for format specifiers

