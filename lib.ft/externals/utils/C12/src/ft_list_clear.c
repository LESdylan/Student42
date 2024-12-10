/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:46:51 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:59:35 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
void ft_list_clear(t_list **begin_list, void (*free_fct)(void *)) {
    t_list *current;
    t_list *next;

    // If the list is empty, there's nothing to clear
    if (*begin_list == NULL) {
        return;
    }

    // Start from the head of the list
    current = *begin_list;

    // Traverse the list
    while (current != NULL) {
        next = current->next; // Save the next node
        free_fct(current->data); // Free the data using the provided function
        free(current); // Free the current node
        current = next; // Move to the next node
    }

    // After clearing all elements, set the list to NULL
    *begin_list = NULL;
}
