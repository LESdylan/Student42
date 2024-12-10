/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:42:21 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 14:42:36 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// ft_map function definition
int *ft_map(int *tab, int length, int(*f)(int)) {
    // Allocate memory for the new array that will store the results
    int *result = (int *)malloc(length * sizeof(int));
    if (result == NULL) {
        // If memory allocation fails, return NULL
        return NULL;
    }

    // Apply function f to each element in the array and store the result
    for (int i = 0; i < length; i++) {
        result[i] = f(tab[i]);
    }

    return result;  // Return the new array
}

// Example function to be used with ft_map
int square(int n) {
    return n * n;
}

int main() {
    int tab[] = {1, 2, 3, 4, 5};  // Example array
    int length = 5;  // Length of the array
    
    // Call ft_map to apply the square function to each element
    int *squared_values = ft_map(tab, length, &square);
    
    if (squared_values != NULL) {
        // Print the squared values
        for (int i = 0; i < length; i++) {
            printf("%d ", squared_values[i]);
        }
        printf("\n");

        // Free the allocated memory
        free(squared_values);
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
