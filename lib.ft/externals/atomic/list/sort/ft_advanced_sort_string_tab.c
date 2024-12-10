/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:01:42 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:01:51 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *)) {
    int i, j;
    char *temp;

    // We first need to count the number of elements in the array to avoid going past the end.
    // We assume the array is null-terminated.
    for (i = 0; tab[i] != NULL; i++) {}

    // Bubble sort: Compare each pair of adjacent elements and swap if necessary.
    for (i = 0; tab[i] != NULL; i++) {
        for (j = i + 1; tab[j] != NULL; j++) {
            // Compare the strings using the provided comparison function
            if (cmp(tab[i], tab[j]) > 0) {
                // Swap the pointers if they are in the wrong order
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

// Example comparison function: ft_strcmp (standard lexicographical comparison)
int ft_strcmp(char *s1, char *s2) {
    while (*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// Example usage
int main() {
    char *tab[] = {"apple", "orange", "banana", "kiwi", NULL};

    // Sort the array using ft_strcmp
    ft_advanced_sort_string_tab(tab, &ft_strcmp);

    // Print the sorted array
    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s\n", tab[i]);
    }

    return 0;
}
