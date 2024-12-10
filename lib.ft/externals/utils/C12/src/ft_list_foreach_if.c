/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:54:31 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:59:19 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)(void *, void *)) {
    t_list *current = begin_list;

    // Traverse the list and apply function f to matching nodes
    while (current != NULL) {
        if (cmp(current->data, data_ref) == 0) {  // If comparison returns 0, apply function f
            f(current->data);
        }
        current = current->next;  // Move to the next node
    }
}
