/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:04:48 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 17:49:41 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

#define HEX_LOW_BASE "0123456789abcdef"
#define HEX_UPP_BASE "0123456789ABCDEF"

void	ft_putchar_pf(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_putstr_pf(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_pf(*str, counter);
		str++;
	}
}

void	ft_putnbr_pf(int n, size_t *counter)
{
	if (n == -2147483648) // Handle INT_MIN edge case
	{
		ft_putstr_pf("-2147483648", counter);
		return;
	}
	if (n < 0)
	{
		ft_putchar_pf('-', counter);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_pf(n / 10, counter);
	ft_putchar_pf(n % 10 + '0', counter);
}

void	ft_putuint_pf(unsigned int n, size_t *counter)
{
	if (n >= 10)
		ft_putuint_pf(n / 10, counter);
	ft_putchar_pf(n % 10 + '0', counter);
}

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	unsigned long p = (unsigned long)ptr;
	ft_putstr_pf("0x", counter);
	if (p == 0)
		ft_putchar_pf('0', counter);
	else
	{
		char hex[16];
		char *hex_base = HEX_LOW_BASE;
		int i = 0;
		while (p)
		{
			hex[i++] = hex_base[p % 16];
			p /= 16;
		}
		while (--i >= 0)
			ft_putchar_pf(hex[i], counter);
	}
}

void	ft_puthex_pf(unsigned int n, size_t *counter, char *base)
{
	char hex[8];
	int i = 0;
	while (n)
	{
		hex[i++] = base[n % 16];
		n /= 16;
	}
	while (--i >= 0)
		ft_putchar_pf(hex[i], counter);
}

void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(va, int), counter);
	else if (*str == 's')
		ft_putstr_pf(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_putptr_pf(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr_pf(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_putuint_pf(va_arg(va, unsigned int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_puthex_pf(va_arg(va, unsigned int), counter, HEX_LOW_BASE);
		else
			ft_puthex_pf(va_arg(va, unsigned int), counter, HEX_UPP_BASE);
	}
	else if (*str == '%')
		ft_putchar_pf('%', counter);  // Handle the percent sign explicitly
}

int	ft_printf(const char *str, ...)
{
	va_list		va;
	size_t		counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)  // Ensure we don't go past the string
				ft_format(va, (char *)str, &counter);
			else
				break;  // Break the loop if the '%' is the last character in the string
		}
		else
			ft_putchar_pf(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}

/*
int ft_printf(const char *str, ...)
{
    va_list args;
    size_t counter = 0;

    va_start(args, str);
    while (*str)
    {
        if (*str == '%' && *(str + 1) == 'd')
        {
            ft_putnbr_pf(va_arg(args, int), &counter);
            str++;
        }
        else if (*str == '%')
        {
            ft_putchar_pf('%', &counter);
        }
        else
        {
            ft_putchar_pf(*str, &counter);
        }
        str++;
    }
    va_end(args);
    return counter;
}
*/