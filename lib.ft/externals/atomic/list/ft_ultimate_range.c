/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:59:25 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:00:22 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max);

int main() {
    int *range = NULL;
    int min = 5;
    int max = 10;
    
    int size = ft_ultimate_range(&range, min, max);
    
    if (range == NULL) {
        printf("Invalid range.\n");
    } else {
        // Print the range
        printf("Range of numbers from %d to %d (exclusive):\n", min, max);
        for (int i = 0; i < size; i++) {
            printf("%d ", range[i]);
        }
        printf("\n");
        
        // Free the allocated memory
        free(range);
    }

    return 0;
}
//int main() {
//    int *range = NULL;
//    int min = 10;
//    int max = 5;
//    
//    int size = ft_ultimate_range(&range, min, max);
//    
//    if (range == NULL) {
//        printf("Invalid range.\n");
//    }
//
//    return 0;
//}


int ft_ultimate_range(int **range, int min, int max) {
    // If min >= max, return 0 and set *range to NULL
    if (min >= max) {
        *range = NULL;
        return 0;
    }

    // Allocate memory for the array (size is max - min)
    *range = (int *)malloc((max - min) * sizeof(int));
    if (*range == NULL) {
        return 0; // Return 0 if memory allocation fails
    }

    // Fill the array with values from min to max - 1
    for (int i = 0; i < (max - min); i++) {
        (*range)[i] = min + i;
    }

    return max - min; // Return the number of elements in the array
}
