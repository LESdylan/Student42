/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:03:45 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 16:38:45 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
#define FT_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

// Function declarations

// ft_create_elem.c
t_list *ft_create_elem(void *data);

// ft_list_at.c
t_list *ft_list_at(t_list *begin_list, unsigned int nbr);

// ft_list_find.c
t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());

// ft_list_foreach.c
void ft_list_foreach(t_list *begin_list, void (*f)(void *));

// ft_list_foreach_if.c
void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());

// ft_list_clear.c
void ft_list_clear(t_list **begin_list, void (*free_fct)(void *));

// ft_list_last.c
t_list *ft_list_last(t_list *begin_list);

// ft_list_push_back.c
void ft_list_push_back(t_list **begin_list, void *data);

// ft_list_push_front.c
void ft_list_push_front(t_list **begin_list, void *data);

// ft_list_push_strs.c
t_list *ft_list_push_strs(int size, char **strs);

// ft_list_remove_if.c
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

// ft_list_reverse.c
void ft_list_reverse(t_list **begin_list);

// ft_list_reverse_fun.c
void ft_list_reverse_fun(t_list *begin_list);

// ft_list_size.c
int ft_list_size(t_list *begin_list);

// ft_list_sort.c
void ft_list_sort(t_list **begin_list, int (*cmp)());

// ft_sorted_list_insert.c
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());
void ft_list_merge(t_list **begin_list1, t_list *begin_list2);
// ft_sorted_list_merge.c
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

// ft_strcmp.c
int ft_strcmp(char *s1, char *s2);

// print_list.c
void print_list(t_list *list);

// test.c
void test(void);

#endif // FT_LIST_H
