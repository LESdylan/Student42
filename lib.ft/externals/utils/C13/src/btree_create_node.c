/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:56:20 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 17:34:41 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree *btree_create_node(void *item) {
    // Allocate memory for a new node
    t_btree *node = (t_btree *)malloc(sizeof(t_btree));
    if (!node) {
        return NULL; // Allocation failed
    }

    // Initialize the node's fields
    node->item = item;
    node->left = NULL;
    node->right = NULL;

    return node; // Return the address of the new node
}