/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:36:02 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 16:33:49 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_list.h"
#include <stdio.h>
int ft_list_size(t_list *begin_list) {
    int count = 0;
    t_list *current = begin_list;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}
