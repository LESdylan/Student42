/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:06:08 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 17:34:27 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *)) {
    if (!root) {
        return NULL;  // Base case: if the tree is empty, return NULL
    }

    // Search in the left subtree
    void *left_result = btree_search_item(root->left, data_ref, cmpf);
    if (left_result) {
        return left_result;  // If found in the left subtree, return the result
    }

    // Compare the current node with the reference data
    if (cmpf(root->item, data_ref) == 0) {
        return root->item;  // If a match is found, return the item
    }

    // Search in the right subtree
    return btree_search_item(root->right, data_ref, cmpf);
}
