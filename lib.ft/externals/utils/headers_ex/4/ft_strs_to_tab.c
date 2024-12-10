/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:09:50 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:09:51 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_stock_str.h"

// Function to create a new string copy
char *ft_strdup(char *src)
{
    int len = 0;
    while (src[len])
        len++;
    
    char *copy = (char *)malloc(sizeof(char) * (len + 1)); // +1 for the null terminator
    if (!copy)
        return NULL;
    
    for (int i = 0; i < len; i++)
        copy[i] = src[i];
    copy[len] = '\0'; // Null-terminate the copied string
    
    return copy;
}

// Function to convert an array of strings to an array of structures
t_stock_str *ft_strs_to_tab(int ac, char **av)
{
    // Allocate memory for the array of structures, with one extra slot for the null-terminated element
    t_stock_str *array = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
    if (!array)
        return NULL;

    // Iterate over each string in the array `av` and fill the structure
    for (int i = 0; i < ac; i++)
    {
        // Get the size of the current string
        array[i].size = 0;
        while (av[i][array[i].size])
            array[i].size++;
        
        // Assign the original string to the `str` field
        array[i].str = av[i];
        
        // Create a copy of the string and assign it to `copy` field
        array[i].copy = ft_strdup(av[i]);
        if (!array[i].copy) // Check for memory allocation failure
        {
            free(array); // Clean up previously allocated memory
            return NULL;
        }
    }
    
    // Mark the end of the array with a NULL element
    array[ac].str = 0;

    return array;
}
