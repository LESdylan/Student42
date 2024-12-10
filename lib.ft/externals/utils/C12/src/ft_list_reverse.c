/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:49:49 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:59:55 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
void ft_list_reverse(t_list **begin_list) {
    t_list *current = *begin_list;
    t_list *previous = NULL;
    t_list *next_node = NULL;

    // Traverse the list and reverse the links
    while (current != NULL) {
        next_node = current->next;  // Save the next node
        current->next = previous;   // Reverse the current node's link
        previous = current;         // Move previous to current node
        current = next_node;        // Move to the next node in the list
    }

    // Update the head of the list to the last node (which is now the first)
    *begin_list = previous;
}
