/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:35:57 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:36:12 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) {
    if (!lst || !f) return NULL;

    t_list *new_list = NULL;
    t_list *new_node = NULL;

    while (lst) {
        new_node = (t_list *)malloc(sizeof(t_list));
        if (!new_node) {
            ft_lstclear(&new_list, del);
            return NULL;
        }
        new_node->content = f(lst->content);
        new_node->next = NULL;

        // Add to the new list
        if (!new_list) {
            new_list = new_node;
        } else {
            t_list *last = ft_lstlast(new_list);
            last->next = new_node;
        }

        lst = lst->next;
    }
    return new_list;
}

// Test function
#include <string.h>

void *duplicate_content(void *content) {
    return strdup((char *)content);
}

void del_content(void *content) {
    free(content);
}

int main() {
    t_list node3 = { strdup("Third"), NULL };
    t_list node2 = { strdup("Second"), &node3 };
    t_list node1 = { strdup("First"), &node2 };

    t_list *new_list = ft_lstmap(&node1, duplicate_content, del_content);

    for (t_list *curr = new_list; curr; curr = curr->next) {
        printf("%s\n", (char *)curr->content); // Should print "First", "Second", "Third"
    }

    ft_lstclear(&new_list, del_content);
    return 0;
}
