/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:46:27 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 14:46:29 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// ft_count_if function definition
int ft_count_if(char **tab, int length, int (*f)(char*)) {
    int count = 0;
    
    // Loop through the array and apply function f on each element
    for (int i = 0; i < length; i++) {
        if (f(tab[i]) != 0) {  // If function f returns a non-zero value
            count++;
        }
    }
    
    return count;  // Return the count of non-zero results
}

// Example function to be used with ft_count_if
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
    int length = 4;  // Length of the array (excluding the NULL terminator)

    // Call ft_count_if to count strings containing vowels
    int count = ft_count_if(array, length, &has_vowel);

    printf("Number of strings containing vowels: %d\n", count);

    return 0;
}
