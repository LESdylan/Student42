/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:03:45 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 15:36:21 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
#define FT_LIST_H

// Define the t_list structure
typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

// Function prototypes
t_list *ft_create_elem(void *data);
void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);

#endif
