/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:04:11 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:27:17 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
// Function to create a new element in the linked list
#include "ft_list.h"
#include <stdlib.h>

// Function to create a new list element
t_list *ft_create_elem(void *data) {
    t_list *new_elem = (t_list *)malloc(sizeof(t_list));
    if (new_elem == NULL) {
        return NULL;  // Return NULL if memory allocation fails
    }
    new_elem->data = data;  // Set the data of the new element
    new_elem->next = NULL;   // The new element's next pointer is initially NULL
    return new_elem;
}
/*
int main(void)
{
    // Create a new list element with an integer as data
    int value = 42;
    t_list *elem = ft_create_elem(&value);

    // Print the data in the created element
    if (elem != NULL)
        printf("Data: %d\n", *(int *)elem->data); // Dereferencing data to print integer value
    else
        printf("Memory allocation failed.\n");

    // Free the allocated memory (in real programs, you should free the list when done)
    free(elem);
    return 0;
}
*/