/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:47:17 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:21:32 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char *ft_strmapi(const char *s, char (*f)(unsigned int, char)) {
    size_t len = strlen(s);
    char *result = (char *)malloc(len + 1);

    if (!result) return NULL;

    for (unsigned int i = 0; i < len; i++) {
        result[i] = f(i, s[i]);
    }
    result[len] = '\0';
    return result;
}

// Test function
#include <stdio.h>
char to_uppercase(unsigned int index, char c) {
    if (index % 2 == 0) {
        return c - 32;  // Convert to uppercase
    }
    return c;
}

int main() {
    const char *str = "hello world";
    char *result = ft_strmapi(str, to_uppercase);

    if (result) {
        printf("Mapped string: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
/*
#include <stdio.h>
#include <ctype.h>  // for toupper and tolower

// Function that modifies a character based on its index
char modify_char(unsigned int index, char c)
{
    if (index % 2 == 0)
    {
        return (char)toupper((unsigned char)c);  // Convert to uppercase if index is even
    }
    else
    {
        return (char)tolower((unsigned char)c);  // Convert to lowercase if index is odd
    }
}

int main()
{
    // Original string
    char str[] = "hello, world";

    // Create a new string by mapping each character with its index using ft_strmapi
    char *new_str = ft_strmapi(str, modify_char);

    // Check if memory allocation was successful
    if (new_str)
    {
        // Print the original and the new string
        printf("Original string: %s\n", str);
        printf("New string: %s\n", new_str);  // Should print "HeLlO, WoRlD"

        // Free the memory allocated for the new string
        free(new_str);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

*/