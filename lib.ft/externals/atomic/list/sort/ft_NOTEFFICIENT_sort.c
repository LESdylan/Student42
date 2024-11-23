/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:35:18 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/23 18:01:42 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Selection sort iterates through the unsorted portions of a list, 
 * selecting the smallest element each time and moving it to its correct location.
 */

#include <stdio.h>

int main(void)
{
    int vals[] = {5, 14, 154, 641500, 41111, 454, 25, 3, 0};
    int n = sizeof(vals) / sizeof(vals[0]); // Calculate the size of the array
    int i, j, temp;

    // Bubble sort logic
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vals[j] < vals[i])
            {
                temp = vals[i];
                vals[i] = vals[j];
                vals[j] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", vals[i]);
    }
    printf("\n");

    return 0;
}
