/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:03:03 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 16:26:33 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_sort(t_list **begin_list, int (*cmp)()) {
    if (*begin_list == NULL || (*begin_list)->next == NULL) {
        // If the list is empty or has only one element, no need to sort
        return;
    }

    int swapped;
    t_list *current;
    //t_list *prev = NULL;
    t_list *next = NULL;

    // Bubble sort to sort the list
    do {
        swapped = 0;
        current = *begin_list;

        while (current->next != NULL) {
            next = current->next;

            // Compare the data of the current node and the next node
            if (cmp(current->data, next->data) > 0) {
                // Swap the data of the two nodes
                void *temp = current->data;
                current->data = next->data;
                next->data = temp;

                swapped = 1;
            }

            current = current->next;
        }
    } while (swapped);  // Repeat until no more swaps are made
}
