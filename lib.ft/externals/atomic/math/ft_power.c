/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:52:35 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:52:37 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_recursive_power(int nb, int power)
{
    if(power == 0 && nb == 0 || power == 0)
        return 1;
    else if(power == 1)
        return nb;
    else if(power < 0)
        return 0;
    else
        return ft_recursive_power(nb, power - 1) * nb;
}
/*
int main(void)
{
    int nb = 2;
    int power = -25;
    printf("%d", ft_recursive_power(nb, power));       
}
*/