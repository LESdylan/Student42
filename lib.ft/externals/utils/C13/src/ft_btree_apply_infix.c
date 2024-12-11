/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:02:36 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 17:03:01 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void btree_apply_infix(t_btree *root, void (*applyf)(void *)) {
    if (!root) {
        return; // Base case: if the current node is NULL, do nothing
    }

    // Recursively apply the function to the left subtree
    btree_apply_infix(root->left, applyf);

    // Apply the function to the current node's item
    applyf(root->item);

    // Recursively apply the function to the right subtree
    btree_apply_infix(root->right, applyf);
}
