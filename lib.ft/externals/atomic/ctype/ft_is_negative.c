/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_negative.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:23:51 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/26 19:34:05 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
//void ft_is_negative(int n);
//int main(void)
//{
//    ft_is_negative(5);
//    printf("\n");
//}
void ft_is_negative(int n)
{
    (n <0) ? write(1,"N",1): write(1,"Y",1);   
}