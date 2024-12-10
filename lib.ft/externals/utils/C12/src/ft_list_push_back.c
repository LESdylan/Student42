/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:43:48 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:59:03 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
void ft_list_push_back(t_list **begin_list, void *data) {
    t_list *new_elem;
    t_list *last_elem;

    // Create the new element
    new_elem = ft_create_elem(data);

    if (*begin_list == NULL) {
        // If the list is empty, the new element becomes the first element
        *begin_list = new_elem;
    } else {
        // Otherwise, traverse to the last element
        last_elem = *begin_list;
        while (last_elem->next != NULL) {
            last_elem = last_elem->next;  // Move to the next element
        }
        // Set the last element's next pointer to the new element
        last_elem->next = new_elem;
    }
}
