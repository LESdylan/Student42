/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:43:10 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:43:22 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

int main() {
    t_list *list = ft_create_elem("First element");
    ft_list_push_front(&list, "New element");
    ft_list_push_front(&list, "Another element");

    t_list *last_element = ft_list_last(list);
    if (last_element != NULL) {
        printf("Last element data: %s\n", (char *)last_element->data); // Should print "First element"
    } else {
        printf("List is empty.\n");
    }

    return 0;
}
