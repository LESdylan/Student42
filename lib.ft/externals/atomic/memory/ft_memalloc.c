/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:14:45 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:15:11 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>  // for malloc
#include <stddef.h>  // for size_t

void *ft_memalloc(size_t size)
{
    // Allocate memory using malloc
    void *memory = malloc(size);

    // If allocation fails, return NULL
    if (!memory)
        return NULL;

    // Initialize the allocated memory to 0
    // We use `memset` to set all bytes to 0
    for (size_t i = 0; i < size; i++)
    {
        ((unsigned char*)memory)[i] = 0;
    }

    // Return the allocated memory
    return memory;
}

/*
#include <stdlib.h>  // for malloc
#include <string.h>  // for memset

void *ft_memalloc(size_t size)
{
    void *memory = malloc(size);

    if (!memory)
        return NULL;

    // Set the allocated memory to 0 using memset
    memset(memory, 0, size);

    return memory;
}

*/

#include <stdio.h>

int main()
{
    size_t size = 10;
    void *mem = ft_memalloc(size);

    if (mem == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Use the memory (e.g., print the memory values, which should all be 0)
    unsigned char *arr = (unsigned char *)mem;
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);  // Should print 0 for each byte
    }

    // Free the allocated memory
    free(mem);
    
    return 0;
}
