/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:04:31 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 16:26:56 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void print_list(t_list *list) {
    while (list != NULL) {
        printf("%s -> ", (char *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}
