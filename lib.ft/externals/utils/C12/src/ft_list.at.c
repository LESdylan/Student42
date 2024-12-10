/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:49:07 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:49:08 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a list with some data
    t_list *list = ft_create_elem("First");
    ft_list_push_front(&list, "Second");
    ft_list_push_front(&list, "Third");

    // Get the 1st element (index 1)
    t_list *element = ft_list_at(list, 1);
    if (element != NULL) {
        printf("Element at index 1: %s\n", (char *)element->data);
    } else {
        printf("Element at index 1 not found.\n");
    }

    // Try to get an out-of-bounds index (e.g., index 5)
    element = ft_list_at(list, 5);
    if (element != NULL) {
        printf("Element at index 5: %s\n", (char *)element->data);
    } else {
        printf("Element at index 5 not found.\n");
    }

    return 0;
}
