/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:33:30 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:33:41 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Define the list node structure
typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;


void ft_lstclear(t_list **lst, void (*del)(void *)) {
    t_list *temp;

    if (!lst || !del) return;

    while (*lst) {
        temp = (*lst)->next;
        del((*lst)->content);
        free(*lst);
        *lst = temp;
    }
    *lst = NULL;
}

// Test function
#include <string.h>

// Example delete function
void del(void *content) {
    free(content); // Assuming content was dynamically allocated
}

int main() {
    t_list *list = ft_lstnew(strdup("Node 1"));
    ft_lstadd_front(&list, ft_lstnew(strdup("Node 2")));
    ft_lstadd_front(&list, ft_lstnew(strdup("Node 3")));

    printf("Before clearing: ");
    print_list(list); // Should print: "Node 3 -> Node 2 -> Node 1 -> NULL"

    ft_lstclear(&list, del);

    printf("After clearing: ");
    print_list(list); // Should print: "NULL"

    return 0;
}
