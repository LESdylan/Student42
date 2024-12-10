/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:58:27 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:58:34 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int min, int max) {
    // Check if min is greater than or equal to max, return NULL in that case
    if (min >= max) {
        return NULL;
    }

    // Allocate memory for the array, size is max - min
    int *range = (int *)malloc((max - min) * sizeof(int));
    if (range == NULL) {
        return NULL;  // Return NULL if memory allocation fails
    }

    // Fill the array with values from min to max - 1
    for (int i = 0; i < (max - min); i++) {
        range[i] = min + i;
    }

    return range; // Return the array
}

#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max);

int main() {
    int min = 5, max = 10;
    int *range = ft_range(min, max);
    
    if (range == NULL) {
        printf("Invalid range or memory allocation failure.\n");
    } else {
        // Print the values in the range
        for (int i = 0; i < (max - min); i++) {
            printf("%d ", range[i]);
        }
        printf("\n");
        
        // Don't forget to free the memory!
        free(range);
    }

    return 0;
}
