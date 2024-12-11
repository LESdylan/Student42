/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:24:16 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:24:29 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>  // for malloc

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    // If the string is NULL, or if the starting index is beyond the string length, return NULL
    if (!s)
        return NULL;

    // Check if the start index is valid
    if (start >= (unsigned int)strlen(s))  // strlen ensures the string length is valid
        return NULL;

    // Allocate memory for the substring, including space for the null terminator
    char *sub = (char *)malloc(sizeof(char) * (len + 1));  // +1 for the null terminator

    // If memory allocation fails, return NULL
    if (!sub)
        return NULL;

    // Copy the substring from the original string
    size_t i = 0;
    while (i < len && s[start + i] != '\0')  // Make sure we don't go past the end of the string
    {
        sub[i] = s[start + i];  // Copy the character
        i++;
    }

    // Null-terminate the substring
    sub[i] = '\0';

    return sub;
}

#include <stdio.h>

int main()
{
    char str[] = "Hello, World!";
    
    // Test valid substring
    char *sub1 = ft_strsub(str, 7, 5);  // Substring from index 7, length 5 ("World")
    printf("Substring 1: %s\n", sub1);  // Should print "World"
    free(sub1);  // Don't forget to free the allocated memory

    // Test invalid substring (start index out of bounds)
    char *sub2 = ft_strsub(str, 20, 5);  // Invalid start index
    printf("Substring 2: %s\n", sub2);  // Should print "(null)" as it returns NULL
    
    // Test valid substring (start at 0)
    char *sub3 = ft_strsub(str, 0, 5);  // Substring from index 0, length 5 ("Hello")
    printf("Substring 3: %s\n", sub3);  // Should print "Hello"
    free(sub3);  // Don't forget to free the allocated memory

    return 0;
}
