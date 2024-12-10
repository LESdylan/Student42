/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:34:11 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:34:47 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Define the list node structure
typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;
#include <stdio.h>
#include <string.h>

// Example delete function
void del(void *content) {
    free(content); // Assuming content was dynamically allocated
}

// Helper function to create a new node
t_list *ft_lstnew(void *content) {
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node) return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

int main() {
    // Create a single node with dynamically allocated content
    t_list *node = ft_lstnew(strdup("Test Node"));
    if (!node) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Before deletion: %s\n", (char *)node->content);

    // Delete the node
    ft_lstdelone(node, del);

    printf("After deletion: Node deleted successfully.\n");

    return 0;
}
