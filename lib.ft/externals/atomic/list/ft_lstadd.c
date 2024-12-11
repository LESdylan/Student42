/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:43:44 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:45:13 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>  // for malloc (if needed for creating the list nodes)
#include <stdio.h>
typedef struct s_list
{
    void *content;
    size_t content_size;
    struct s_list *next;
} t_list;

void ft_lstadd(t_list **alst, t_list *new)
{
    if (alst && new)  // Ensure the input pointers are not NULL
    {
        new->next = *alst;  // Make the new node point to the current head
        *alst = new;        // Update the head of the list to point to the new node
    }
}

// Function to print the list (for demonstration purposes)
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);  // Assuming content is a string
        lst = lst->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create new nodes for the linked list
    t_list *node1 = malloc(sizeof(t_list));
    node1->content = "Node 1";
    node1->content_size = 6;
    node1->next = NULL;

    t_list *node2 = malloc(sizeof(t_list));
    node2->content = "Node 2";
    node2->content_size = 6;
    node2->next = NULL;

    // Initially, the list is just node1
    t_list *list = node1;

    // Add node2 at the beginning of the list
    ft_lstadd(&list, node2);

    // Print the list after adding node2
    print_list(list);  // Output should be: Node 2 -> Node 1 -> NULL

    // Free the allocated memory (for completeness)
    free(node1);
    free(node2);

    return 0;
}
