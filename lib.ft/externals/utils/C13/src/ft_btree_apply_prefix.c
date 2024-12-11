/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:57:33 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 16:57:45 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void btree_apply_prefix(t_btree *root, void (*applyf)(void *)) {
    if (!root) {
        return; // Base case: do nothing if the current node is NULL
    }
    
    // Apply the function to the current node's item
    applyf(root->item);

    // Recursively apply the function to the left subtree
    btree_apply_prefix(root->left, applyf);

    // Recursively apply the function to the right subtree
    btree_apply_prefix(root->right, applyf);
}
