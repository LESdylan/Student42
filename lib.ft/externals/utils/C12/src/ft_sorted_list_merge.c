/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:10:42 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 16:11:33 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)()) {
    t_list *current1;
    t_list *current2;
    t_list *prev1;
    
    if (!begin_list2) {
        return;  // Nothing to merge if the second list is empty
    }

    current1 = *begin_list1;
    current2 = begin_list2;
    prev1 = NULL;

    while (current2 != NULL) {
        // Find the correct position in begin_list1 for the element in begin_list2
        while (current1 != NULL && (*cmp)(current1->data, current2->data) < 0) {
            prev1 = current1;
            current1 = current1->next;
        }

        // Insert current2 into the sorted list begin_list1
        t_list *next2 = current2->next;

        // If inserting at the head of begin_list1
        if (prev1 == NULL) {
            current2->next = *begin_list1;
            *begin_list1 = current2;
        } else {
            prev1->next = current2;
            current2->next = current1;
        }

        // Move to the next element in begin_list2
        current2 = next2;
        current1 = *begin_list1;  // Reset current1 to the head of begin_list1
        prev1 = NULL;              // Reset prev1
    }
}
