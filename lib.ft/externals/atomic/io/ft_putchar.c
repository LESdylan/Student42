/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:19:25 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/26 19:23:10 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void ft_putchar(char c)
{
    write(1,&c,1);   
}
//int main(void)
//{
//    ft_putchar('h');
//    printf("\n");
//    return 0;
//}