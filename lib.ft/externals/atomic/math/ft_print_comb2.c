/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:52:26 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/26 20:05:33 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c);
void ft_print_comb(void);

int main(void)
{
    ft_print_comb();
    return 0;
}

void ft_print_comb(void)
{
    int i, j;
    i = -1;

    while (++i <= 98)
    {
        j = i;
        while (++j <= 99)
        {
            ft_putchar((i / 10) + '0');
            ft_putchar((i % 10) + '0');
            ft_putchar(' ');
            ft_putchar((j / 10) + '0');
            ft_putchar((j % 10) + '0'); 

            if (!(i == 98 && j == 99))
            {
                ft_putchar(',');
                ft_putchar(' ');
            }
        }
    }
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}
