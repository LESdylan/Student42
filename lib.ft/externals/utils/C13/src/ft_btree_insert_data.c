/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:05:35 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 17:05:37 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree *btree_create_node(void *item) {
    t_btree *node = (t_btree *)malloc(sizeof(t_btree));
    if (!node) {
        return NULL;
    }
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *)) {
    if (*root == NULL) {
        // If the tree is empty, create a new node and set it as the root
        *root = btree_create_node(item);
        return;
    }

    // Compare the current node's item with the item to be inserted
    int cmp_result = cmpf(item, (*root)->item);

    if (cmp_result < 0) {
        // If the item is smaller, insert it in the left subtree
        btree_insert_data(&(*root)->left, item, cmpf);
    } else {
        // If the item is greater or equal, insert it in the right subtree
        btree_insert_data(&(*root)->right, item, cmpf);
    }
}
