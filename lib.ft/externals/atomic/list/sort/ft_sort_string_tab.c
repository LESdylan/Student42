/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:00:31 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:00:36 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void ft_sort_string_tab(char **tab) {
    int i, j;
    char *temp;

    // Find the length of the array (assumed to be null-terminated)
    for (i = 0; tab[i] != NULL; i++) {
        // Count elements in the array
    }

    // Bubble sort: iterate over the array and swap elements if needed
    for (i = 0; tab[i] != NULL; i++) {
        for (j = i + 1; tab[j] != NULL; j++) {
            // Compare strings using strcmp
            if (strcmp(tab[i], tab[j]) > 0) {
                // Swap strings if they are out of order
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

// Example usage:
int main() {
    char *tab[] = {"apple", "orange", "banana", "kiwi", NULL};

    ft_sort_string_tab(tab);

    // Print the sorted array
    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s\n", tab[i]);
    }

    return 0;
}
