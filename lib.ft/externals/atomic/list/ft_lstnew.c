/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:36:14 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:36:29 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// Test function
int main() {
    t_list *node = ft_lstnew("Hello, World!");

    if (node) {
        printf("Node content: %s\n", (char *)node->content); // Should print "Hello, World!"
        free(node);
    }
    return 0;
}
