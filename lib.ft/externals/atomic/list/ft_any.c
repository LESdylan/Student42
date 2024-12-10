/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:43:05 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 14:43:20 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// ft_any function definition
int ft_any(char **tab, int (*f)(char*)) {
    int i = 0;

    // Loop through the array until we encounter a NULL pointer
    while (tab[i] != NULL) {
        if (f(tab[i]) != 0) {  // If the function f returns a non-zero value
            return 1;
        }
        i++;
    }
    return 0;  // Return 0 if no element returns a non-zero value
}

// Example function to be used with ft_any
int has_vowel(char *str) {
    // Check if the string contains any vowel
    char *vowels = "aeiouAEIOU";
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; vowels[j] != '\0'; j++) {
            if (str[i] == vowels[j]) {
                return 1;  // Return 1 if a vowel is found
            }
        }
    }
    return 0;  // Return 0 if no vowels are found
}

int main() {
    // Example array of strings
    char *array[] = {"hello", "world", "abc", "xyz", NULL};

    // Call ft_any to check if any string contains a vowel
    int result = ft_any(array, &has_vowel);

    if (result == 1) {
        printf("At least one string contains a vowel.\n");
    } else {
        printf("No string contains a vowel.\n");
    }

    return 0;
}
