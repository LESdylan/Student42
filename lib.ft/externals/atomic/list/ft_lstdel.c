/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:43:03 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:43:53 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>  // for free

// Definition of the t_list structure (assumed from context)
typedef struct s_list
{
    void *content;
    size_t content_size;
    struct s_list *next;
} t_list;

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    t_list *current;
    t_list *next_node;

    // Check if the list is not empty
    if (alst && *alst)
    {
        current = *alst;
        
        // Iterate over the list and free each node
        while (current)
        {
            next_node = current->next;  // Save the next node
            del(current->content, current->content_size);  // Call del to free the content
            free(current);  // Free the current node
            current = next_node;  // Move to the next node
        }

        // Set the pointer to the list to NULL
        *alst = NULL;
    }
}
#include <stdio.h>
#include <stdlib.h>

void del(void *content, size_t size)
{
    (void)size;  // Ignore size, since we're not using it in this example
    free(content);  // Free the content of the node
}

int main()
{
    // Example of creating a simple linked list
    t_list *head = malloc(sizeof(t_list));
    head->content = malloc(10);  // Allocate some memory for the content
    head->content_size = 10;
    head->next = NULL;

    // Delete the entire list
    ft_lstdel(&head, del);

    // At this point, head should be NULL, and memory should be freed
    if (head == NULL)
        printf("List has been deleted and head is NULL.\n");

    return 0;
}
