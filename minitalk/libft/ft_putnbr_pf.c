/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:01:53 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:06:20 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_pf(int num, size_t *counter)
{
    if (num == -2147483648)
    {
        ft_putstr_pf("-2147483648", counter);
        return;
    }
    if (num < 0)
    {
        ft_putchar_pf('-', counter);
        num = -num;
    }
    if (num >= 10)
        ft_putnbr_pf(num / 10, counter);
    ft_putchar_pf((num % 10) + '0', counter);
}
