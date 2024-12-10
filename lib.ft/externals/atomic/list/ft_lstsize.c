/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:36:31 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:36:59 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

#include <stddef.h>

int ft_lstsize(t_list *lst) {
    int count = 0;

    while (lst) {
        count++;
        lst = lst->next;
    }
    return count;
}

// Test function
int main() {
    t_list node3 = { "Third", NULL };
    t_list node2 = { "Second", &node3 };
    t_list node1 = { "First", &node2 };

    printf("List size: %d\n", ft_lstsize(&node1)); // Should print 3
    return 0;
}
