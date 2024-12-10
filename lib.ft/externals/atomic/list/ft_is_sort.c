/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:47:57 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 14:48:30 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// ft_is_sort function definition
int ft_is_sort(int *tab, int length, int (*f)(int, int)) {
    // Loop through the array and compare each adjacent pair of elements
    for (int i = 0; i < length - 1; i++) {
        if (f(tab[i], tab[i + 1]) > 0) {  // If the order is violated
            return 0;  // The array is not sorted
        }
    }
    return 1;  // The array is sorted
}

// Example comparison function: returns negative, zero, or positive integer
int compare(int a, int b) {
    if (a < b) return -1;  // a is smaller than b
    if (a > b) return 1;   // a is greater than b
    return 0;               // a is equal to b
}

int main() {
    // Example array that is sorted
    int tab1[] = {1, 2, 3, 4, 5};
    int length1 = 5;

    // Example array that is not sorted
    int tab2[] = {5, 3, 4, 1, 2};
    int length2 = 5;

    // Check if tab1 is sorted
    int result1 = ft_is_sort(tab1, length1, compare);
    printf("Is tab1 sorted? %d\n", result1);  // Expected output: 1

    // Check if tab2 is sorted
    int result2 = ft_is_sort(tab2, length2, compare);
    printf("Is tab2 sorted? %d\n", result2);  // Expected output: 0

    return 0;
}
