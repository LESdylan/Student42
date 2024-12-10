/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:07:59 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 16:08:49 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)()) {
    t_list *new_elem;
    t_list *current;
    
    // Create the new element
    new_elem = ft_create_elem(data);
    
    // If the list is empty or the new element should be the first
    if (*begin_list == NULL || (*cmp)(data, (*begin_list)->data) <= 0) {
        new_elem->next = *begin_list;
        *begin_list = new_elem;
        return;
    }

    // Traverse the list to find the correct insertion point
    current = *begin_list;
    while (current->next != NULL && (*cmp)(data, current->next->data) > 0) {
        current = current->next;
    }

    // Insert the new element in the correct position
    new_elem->next = current->next;
    current->next = new_elem;
}
