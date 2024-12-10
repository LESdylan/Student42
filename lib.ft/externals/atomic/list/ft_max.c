/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:41:54 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:37:59 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

#include <stddef.h>

int ft_max(int *arr, size_t size) {
    if (!arr || size == 0) return 0;

    int max = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Test function
#include <stdio.h>

int main() {
    int numbers[] = { 1, 3, 7, 2, 5 };
    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Max value: %d\n", ft_max(numbers, size)); // Should print 7
    return 0;
}
