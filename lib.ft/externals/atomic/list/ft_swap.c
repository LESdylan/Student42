/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:54:26 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:39:35 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_swap(int *a, int *b) {
    if (!a || !b) return;

    int temp = *a;
    *a = *b;
    *b = temp;
}

// Test function
#include <stdio.h>

int main() {
    int x = 5, y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);
    ft_swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y); // Should print "x = 10, y = 5"

    return 0;
}


