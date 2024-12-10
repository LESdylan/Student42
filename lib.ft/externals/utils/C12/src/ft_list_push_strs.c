/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:45:49 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:58:55 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "ft_list.h"

t_list *ft_list_push_strs(int size, char **strs) {
    t_list *list = NULL;
    int i;

    // Iterate through the array of strings backwards
    for (i = size - 1; i >= 0; i--) {
        // Create a new element with the string
        ft_list_push_front(&list, strs[i]);
    }

    // Return the first element of the list
    return list;
}
