/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:16:32 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:16:41 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>  // for malloc

char *ft_strnew(size_t size)
{
    // Allocate memory for the string
    char *str = (char *)malloc(size + 1);  // +1 for the null terminator

    // Check if the memory allocation was successful
    if (str == NULL)
        return NULL;

    // Initialize all characters in the string to '\0'
    for (size_t i = 0; i <= size; i++)  // include space for the null terminator
    {
        str[i] = '\0';
    }

    // Return the initialized string
    return str;
}

#include <stdio.h>

int main()
{
    size_t size = 10;  // Allocate a string of 10 characters
    char *str = ft_strnew(size);

    if (str == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Print the string to verify it's initialized to '\0'
    for (size_t i = 0; i < size; i++)
    {
        printf("'%c' ", str[i]);  // Should print '\0' for each character
    }

    printf("\n");

    // Print the string itself, it should be an empty string since all characters are '\0'
    printf("String: \"%s\"\n", str);  // Should print an empty string

    // Free the allocated memory
    free(str);

    return 0;
}
