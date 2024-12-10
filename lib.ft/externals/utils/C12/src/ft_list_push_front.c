/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:10:12 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:27:08 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
// Function to add a new element to the front of the list
void ft_list_push_front(t_list **begin_list, void *data) {
    // Create a new element
    t_list *new_elem = ft_create_elem(data);

    // If creation was successful, add the new element to the front
    if (new_elem != NULL) {
        new_elem->next = *begin_list;  // Point the new element's next to the current head
        *begin_list = new_elem;        // Update the head of the list to the new element
    }
}
/*
int main() {
    t_list *list = NULL;  // Initially, the list is empty

    // Add some elements to the front of the list
    ft_list_push_front(&list, "first");
    ft_list_push_front(&list, "second");
    ft_list_push_front(&list, "third");

    // Print the list
    t_list *temp = list;
    while (temp != NULL) {
        printf("%s\n", (char *)temp->data);
        temp = temp->next;
    }

    return 0;
}
*/