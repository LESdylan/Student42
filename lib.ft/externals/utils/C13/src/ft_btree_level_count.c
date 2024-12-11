/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:07:51 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 17:08:25 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

// Function to calculate the depth of the largest branch
int btree_level_count(t_btree *root) {
    if (!root) {
        return 0; // Base case: If the tree is empty, the depth is 0
    }

    // Recursively calculate the depth of the left and right subtrees
    int left_depth = btree_level_count(root->left);
    int right_depth = btree_level_count(root->right);

    // Return the maximum of the left and right depths plus 1 (for the current node)
    if (left_depth > right_depth) {
        return left_depth + 1;
    } else {
        return right_depth + 1;
    }
}
