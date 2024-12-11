/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:15:41 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:15:54 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>  // for free

void ft_memdel(void **ap)
{
    // Check if the pointer is not NULL
    if (ap && *ap)
    {
        // Free the memory that the pointer points to
        free(*ap);

        // Set the pointer to NULL
        *ap = NULL;
    }
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Example allocation
    size_t size = 10;
    void *mem = malloc(size);

    if (mem == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Use the memory (e.g., set some values)
    unsigned char *arr = (unsigned char *)mem;
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (unsigned char)(i);  // Fill with some values
    }

    // Print the values
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the memory and set the pointer to NULL
    ft_memdel(&mem);

    // After calling ft_memdel, the pointer should be NULL
    if (mem == NULL)
    {
        printf("Memory successfully freed and pointer set to NULL.\n");
    }
    else
    {
        printf("Pointer was not set to NULL.\n");
    }

    return 0;
}
