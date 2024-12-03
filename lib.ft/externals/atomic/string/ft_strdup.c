/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:07:02 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/03 12:24:30 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(const char *s);
int main()
{
    const char *str = "hello world";
    char *dup = ft_strdup(str);
    printf("%s\n", strdup(str)); // Testing with the standard strdup
    printf("%s\n", dup);        // Testing with your implementation
    free(dup);
    return 0;
}

char *ft_strdup(const char *s)
{
    // Allocate memory for the duplicate string
    size_t len = strlen(s) + 1; // +1 for the null terminator
    char *dup = (char *) malloc(len);
    if (!dup)                   // Check for allocation failure
        return NULL;

    // Copy the string into the allocated memory
    char *ptr = dup;
    while (*s != '\0')
        *ptr++ = *s++;
    *ptr = '\0';                // Null-terminate the new string

    return dup;                 // Return the start of the duplicated string
}
