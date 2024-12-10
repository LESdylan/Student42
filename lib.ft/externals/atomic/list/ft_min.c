/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:50:02 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:39:26 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_min(int *arr, size_t size) {
    if (!arr || size == 0) return 0;

    int min = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Test function
#include <stdio.h>

int main() {
    int numbers[] = { 5, 2, 8, -1, 7 };
    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Min value: %d\n", ft_min(numbers, size)); // Should print -1
    return 0;
}
