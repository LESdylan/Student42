/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:16:56 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:17:26 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>  // for free

void ft_strdel(char **as)
{
    // Check if the input pointer is not NULL and the string pointer is not NULL
    if (as && *as)
    {
        // Free the memory that the string points to
        free(*as);

        // Set the pointer to NULL to prevent a dangling pointer
        *as = NULL;
    }
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Example allocation for a string
    char *str = malloc(20 * sizeof(char));  // Allocate 20 bytes for a string

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

    printf("Before free: %s\n", str);  // Print the string

    // Free the string and set the pointer to NULL
    ft_strdel(&str);

    // After calling ft_strdel, the pointer should be NULL
    if (str == NULL)
    {
        printf("String memory successfully freed and pointer set to NULL.\n");
    }
    else
    {
        printf("Pointer was not set to NULL.\n");
    }

    return 0;
}
