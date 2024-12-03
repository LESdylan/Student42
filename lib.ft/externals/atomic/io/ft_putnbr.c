/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:06:01 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/26 23:22:18 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// recursive version
#include <unistd.h>
#include <stdio.h>
#define MIN_INT -2147483648
void ft_putnbr(int nb)
{
    char result;
    
    if(nb == MIN_INT)
    {
        write(1,"-",1);
        write(1,"2147483648",10);
        return;
    }
    if(nb < 0)
    {
        write(1,"-",1);
        nb = -nb;
    }
    if(nb > 9)
        ft_putnbr(nb / 10);
    result  = nb%10+'0';
    write(1, &result, 1);
}
int main(void)
{
    ft_putnbr(-2147483648);
    printf("\n");
    ft_putnbr(123);
    printf("\n");
}