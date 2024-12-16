/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:06:36 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:06:38 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putuint_pf(unsigned int num, size_t *counter)
{
    if (num >= 10)
        ft_putuint_pf(num / 10, counter);
    ft_putchar_pf((num % 10) + '0', counter);
}
