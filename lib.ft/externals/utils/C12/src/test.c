/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:19:48 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:36:46 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

int main() {
    t_list *list = ft_create_elem("First element");
    ft_list_push_front(&list, "New element");
    ft_list_push_front(&list, "Another element");

    printf("List size: %d\n", ft_list_size(list));  // Should print 3

    return 0;
}
