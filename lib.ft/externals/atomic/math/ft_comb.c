/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:35:24 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/26 19:51:47 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c);
void ft_print_comb(void);


int main(void)
{
    ft_print_comb();
    return 0;
}
void ft_print_comb(void)
{
    int i,j,k;
    i = -1;
    while(++i <= 7)
    {
        j = i;
        while(++j <= 8)
        {
            k = j;
            while(++k <=9)
            {
                ft_putchar(i + 48);
                ft_putchar(j + 48);
                ft_putchar(k + 48);
                ft_putchar(',');
                ft_putchar(' ');
            }
        }
    }
}

void ft_putchar(char c)
{
    write(1,&c,1);
}