/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:56:56 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 17:25:55 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_btree.h"

// Function to compare two strings (similar to strcmp)
int cmpf(void *a, void *b) {
    return strcmp((char *)a, (char *)b);
}

// Function to create a new node
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

// Function to insert data into the tree
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *)) {
    if (*root == NULL) {
        *root = btree_create_node(item);
        return;
    }
    int cmp_result = cmpf(item, (*root)->item);
    if (cmp_result < 0) {
        btree_insert_data(&(*root)->left, item, cmpf);
    } else {
        btree_insert_data(&(*root)->right, item, cmpf);
    }
}

// Function to apply a function to each element in preorder
void btree_apply_prefix(t_btree *root, void (*applyf)(void *item)) {
    if (root == NULL) {
        return;
    }
    applyf(root->item);  // Apply the function to the root
    btree_apply_prefix(root->left, applyf);  // Traverse the left subtree
    btree_apply_prefix(root->right, applyf);  // Traverse the right subtree
}

// Function to apply a function to each element in infix order
void btree_apply_infix(t_btree *root, void (*applyf)(void *item)) {
    if (root == NULL) {
        return;
    }
    btree_apply_infix(root->left, applyf);  // Traverse the left subtree
    applyf(root->item);  // Apply the function to the root
    btree_apply_infix(root->right, applyf);  // Traverse the right subtree
}

// Function to apply a function to each element in postfix order
void btree_apply_suffix(t_btree *root, void (*applyf)(void *item)) {
    if (root == NULL) {
        return;
    }
    btree_apply_suffix(root->left, applyf);  // Traverse the left subtree
    btree_apply_suffix(root->right, applyf);  // Traverse the right subtree
    applyf(root->item);  // Apply the function to the root
}

// Function to search for an item in the tree (infix traversal)
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *)) {
    if (root == NULL) {
        return NULL;
    }
    int cmp_result = cmpf(data_ref, root->item);
    if (cmp_result == 0) {
        return root->item;  // Item found
    }
    if (cmp_result < 0) {
        return btree_search_item(root->left, data_ref, cmpf);  // Search left subtree
    } else {
        return btree_search_item(root->right, data_ref, cmpf);  // Search right subtree
    }
}

// Function to print the tree node (for visualization)
void print_node(void *item) {
    printf("%s ", (char *)item);
}

// Function to print the tree (using infix traversal)
void print_tree(t_btree *root) {
    printf("Infix Traversal: ");
    btree_apply_infix(root, print_node);
    printf("\n");
}

// Main program to test the functions
int main() {
    t_btree *root = NULL;

    // Insert data into the tree
    printf("Inserting data into the tree...\n");
    btree_insert_data(&root, "Banana", cmpf);
    btree_insert_data(&root, "Apple", cmpf);
    btree_insert_data(&root, "Orange", cmpf);
    btree_insert_data(&root, "Grape", cmpf);

    // Print the tree using infix traversal
    print_tree(root);

    // Apply prefix traversal to print the tree nodes
    printf("Prefix Traversal: ");
    btree_apply_prefix(root, print_node);
    printf("\n");

    // Apply suffix traversal to print the tree nodes
    printf("Suffix Traversal: ");
    btree_apply_suffix(root, print_node);
    printf("\n");

    // Search for an item in the tree
    char *search_item = "Orange";
    char *result = (char *)btree_search_item(root, search_item, cmpf);

    if (result) {
        printf("Found: %s\n", result);
    } else {
        printf("Item not found\n");
    }

    return 0;
}
