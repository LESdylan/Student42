/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:50 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:59:11 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
void ft_list_foreach(t_list *begin_list, void (*f)(void *)) {
    t_list *current = begin_list;

    // Traverse the list and apply function f to each node's data
    while (current != NULL) {
        f(current->data);  // Apply the function f to the current node's data
        current = current->next;  // Move to the next node
    }
}
