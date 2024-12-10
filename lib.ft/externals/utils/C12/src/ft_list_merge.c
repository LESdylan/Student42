/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:01:13 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 16:02:07 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
void ft_list_merge(t_list **begin_list1, t_list *begin_list2) {
    if (*begin_list1 == NULL) {
        // If the first list is empty, simply make begin_list1 point to begin_list2
        *begin_list1 = begin_list2;
        return;
    }

    t_list *current = *begin_list1;

    // Traverse to the last element of begin_list1
    while (current->next != NULL) {
        current = current->next;
    }

    // Attach the second list to the end of the first list
    current->next = begin_list2;
}
