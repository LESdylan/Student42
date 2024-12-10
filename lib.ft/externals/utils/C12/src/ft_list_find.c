/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:55:42 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:59:25 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)(void *, void *)) {
    t_list *current = begin_list;

    // Traverse the list
    while (current != NULL) {
        if (cmp(current->data, data_ref) == 0) {  // If data matches the reference
            return current;  // Return the node where the data matches
        }
        current = current->next;  // Move to the next node
    }

    // If no match is found, return NULL
    return NULL;
}
