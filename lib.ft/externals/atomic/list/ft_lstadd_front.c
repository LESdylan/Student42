/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:32:00 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:33:18 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Define the list node structure
typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

void ft_lstadd_front(t_list **lst, t_list *new_node) {
    if (!lst || !new_node) return;
    new_node->next = *lst;
    *lst = new_node;
}

// Test function
#include <stdio.h>

// Helper function to create a new node
t_list *ft_lstnew(void *content) {
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node) return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

void print_list(t_list *lst) {
    while (lst) {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main() {
    t_list *list = NULL;

    t_list *node1 = ft_lstnew("Second");
    t_list *node2 = ft_lstnew("First");

    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);

    print_list(list); // Should print: "First -> Second -> NULL"

    return 0;
}
