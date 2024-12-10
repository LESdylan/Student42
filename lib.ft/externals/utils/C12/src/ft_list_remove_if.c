/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:57:29 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:58:47 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *), void (*free_fct)(void *)) {
    t_list *current = *begin_list;
    t_list *previous = NULL;

    // Traverse the list
    while (current != NULL) {
        if (cmp(current->data, data_ref) == 0) {
            // Data matches, remove the node

            // If it's the first node, update begin_list
            if (previous == NULL) {
                *begin_list = current->next;
            } else {
                previous->next = current->next;
            }

            // Free the node's data and the node itself
            free_fct(current->data);
            free(current);

            // Move to the next node
            current = *begin_list;
            previous = NULL;
        } else {
            // Move to the next node if no match
            previous = current;
            current = current->next;
        }
    }
}
