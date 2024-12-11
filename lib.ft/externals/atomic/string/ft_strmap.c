/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:20:00 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:20:24 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>  // for malloc

char *ft_strmap(char const *s, char (*f)(char))
{
    // Check if the string or function is NULL
    if (!s || !f)
        return NULL;

    // Allocate memory for the new string (same size as the original string)
    size_t len = 0;
    while (s[len])  // Find the length of the string
        len++;

    // Allocate memory for the new string and include space for the null terminator
    char *new_str = (char *)malloc(sizeof(char) * (len + 1));

    // Check if memory allocation was successful
    if (!new_str)
        return NULL;

    // Apply the function f to each character of the string
    for (size_t i = 0; i < len; i++)
    {
        new_str[i] = f(s[i]);  // Apply function f to each character
    }

    // Null-terminate the new string
    new_str[len] = '\0';

    return new_str;
}

#include <stdio.h>
#include <ctype.h>  // for toupper

// Function that converts a character to uppercase
char to_uppercase(char c)
{
    return (char)toupper((unsigned char)c);  // Convert to uppercase
}
#include <stdio.h>
#include <ctype.h>  // for toupper

// Function that converts a character to uppercase
char to_uppercase(char c)
{
    return (char)toupper((unsigned char)c);  // Convert to uppercase
}

int main()
{
    // Original string
    char str[] = "hello, world";

    // Create a new string by mapping each character to uppercase using ft_strmap
    char *new_str = ft_strmap(str, to_uppercase);

    // Check if memory allocation was successful
    if (new_str)
    {
        // Print the original and the new string
        printf("Original string: %s\n", str);
        printf("New string: %s\n", new_str);  // Should print "HELLO, WORLD"

        // Free the memory allocated for the new string
        free(new_str);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
