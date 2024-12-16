/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:06:04 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:06:05 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_puthex_helper(unsigned int num, size_t *counter, char *base)
{
    if (num >= 16)
        ft_puthex_helper(num / 16, counter, base);
    ft_putchar_pf(base[num % 16], counter);
}

void ft_puthex_pf(unsigned int num, size_t *counter, char *base)
{
    ft_puthex_helper(num, counter, base);
}