/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:05:57 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 16:06:06 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
void ft_list_reverse_fun(t_list *begin_list) {
    t_list *prev = NULL;
    t_list *current = begin_list;
    t_list *next = NULL;

    // If the list is empty or contains only one element, no reversal is needed
    if (begin_list == NULL || begin_list->next == NULL) {
        return;
    }

    // Traverse the list and reverse the links
    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's next pointer
        prev = current;        // Move prev and current one step forward
        current = next;
    }

    // After the loop, prev will be the new head of the list
    begin_list = prev;
}
