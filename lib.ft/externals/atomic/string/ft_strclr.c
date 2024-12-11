/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:17:48 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:18:01 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>  // for NULL

void ft_strclr(char *s)
{
    // Check if the input string is not NULL
    if (s)
    {
        // Iterate through each character of the string and set it to '\0'
        while (*s)
        {
            *s = '\0';  // Set the current character to the null terminator
            s++;        // Move to the next character in the string
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for a string
    char *str = malloc(20 * sizeof(char));

    if (str == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Assign some values to the string
    for (int i = 0; i < 19; i++) {
        str[i] = 'A' + i;  // Fill with letters from 'A' to 'S'
    }
    str[19] = '\0';  // Null-terminate the string

    // Print the string before clearing
    printf("Before clear: %s\n", str);

    // Clear the string
    ft_strclr(str);

    // Print the string after clearing
    printf("After clear: \"%s\"\n", str);  // Should print an empty string

    // Free the allocated memory
    free(str);

    return 0;
}
