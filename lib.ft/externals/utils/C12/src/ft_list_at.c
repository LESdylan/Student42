/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:48:11 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:59:47 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
t_list *ft_list_at(t_list *begin_list, unsigned int nbr) {
    t_list *current = begin_list;
    unsigned int index = 0;

    // Traverse the list to the nth element
    while (current != NULL) {
        if (index == nbr) {
            return current; // Return the node when the index is found
        }
        current = current->next; // Move to the next node
        index++;
    }

    // If we reach here, the index was out of bounds
    return NULL;
}
