/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:35:47 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:35:55 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstlast(t_list *lst) {
    if (!lst) return NULL;

    while (lst->next) {
        lst = lst->next;
    }
    return lst;
}

// Test function
#include <stdio.h>

int main() {
    t_list node3 = { "Third", NULL };
    t_list node2 = { "Second", &node3 };
    t_list node1 = { "First", &node2 };

    t_list *last = ft_lstlast(&node1);
    if (last) {
        printf("Last node content: %s\n", (char *)last->content); // Should print "Third"
    }
    return 0;
}
