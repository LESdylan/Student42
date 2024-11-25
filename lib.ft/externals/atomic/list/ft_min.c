/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:50:02 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/11/25 13:41:40 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Function to find the minimum value in one pass
int find_minimum_in_one_pass(int array[], int size) {
    // Initialize the minimum value with the first element of the array
    int min_value = array[0];

    // Traverse the array starting from the second element
    for (int i = 1; i < size; i++) {
        if (array[i] < min_value) {
            min_value = array[i]; // Update the minimum value
        }
    }

    return min_value;
}

int main() {
    int array[] = {5, 5415, 4, 3, 511}; // Example array
    int size = sizeof(array) / sizeof(array[0]);

    // Call the function to find the minimum value
    int minimum = find_minimum_in_one_pass(array, size);

    // Print the result
    printf("The minimum value is: %d\n", minimum);

    return 0;
}
