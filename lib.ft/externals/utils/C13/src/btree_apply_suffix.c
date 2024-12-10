/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:04:34 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 17:04:36 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void btree_apply_suffix(t_btree *root, void (*applyf)(void *)) {
    if (!root) {
        return; // Base case: do nothing if the current node is NULL
    }

    // Recursively apply the function to the left subtree
    btree_apply_suffix(root->left, applyf);

    // Recursively apply the function to the right subtree
    btree_apply_suffix(root->right, applyf);

    // Apply the function to the current node's item
    applyf(root->item);
}
