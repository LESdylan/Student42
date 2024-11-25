/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:41:54 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/25 13:52:43 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
// function signature
int ft_max(int array[], int n);
int main()
{
     int array[] = {5, 5415, 4, 3, 511};
     int size = sizeof(array) / sizeof(array[0]);
     int max = ft_max(array, size);
     printf("the max value is %d\n", max);
}

int ft_max(int array[], int n)
{
    int val_max, i;

    val_max = array[0];
   
    i = 0;
    while(++i < n)
    {
        if(array[i] > val_max)
        {
            val_max = array[i];   
        }
    }
    return val_max;
}