/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:08:53 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 17:11:29 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

// Structure to hold a node and its level in the queue
typedef struct s_queue_node {
    t_btree *node;
    int level;
} t_queue_node;

// Queue structure to hold nodes for level-order traversal
typedef struct s_queue {
    t_queue_node *nodes;
    int front;
    int rear;
    int capacity;
} t_queue;

// Function to create and initialize a new queue
t_queue *create_queue(int capacity) {
    t_queue *queue = (t_queue *)malloc(sizeof(t_queue));
    if (!queue) return NULL;
    queue->nodes = (t_queue_node *)malloc(sizeof(t_queue_node) * capacity);
    queue->front = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    return queue;
}

// Function to check if the queue is empty
int is_empty(t_queue *queue) {
    return queue->front == queue->rear;
}

// Function to enqueue an element into the queue
void enqueue(t_queue *queue, t_btree *node, int level) {
    if (queue->rear < queue->capacity) {
        queue->nodes[queue->rear].node = node;
        queue->nodes[queue->rear].level = level;
        queue->rear++;
    }
}

// Function to dequeue an element from the queue
t_queue_node dequeue(t_queue *queue) {
    t_queue_node node = queue->nodes[queue->front];
    queue->front++;
    return node;
}

// Function to apply the function to the nodes by level
void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem)) {
    if (!root) return;

    // Create a queue and enqueue the root node with level 0
    t_queue *queue = create_queue(100);  // Initial capacity of 100 nodes
    enqueue(queue, root, 0);
    
    int current_level = -1;
    int is_first_elem = 1;

    while (!is_empty(queue)) {
        // Dequeue a node
        t_queue_node qnode = dequeue(queue);
        t_btree *node = qnode.node;
        int level = qnode.level;

        // If the level changes, mark that the current node is the first node at the new level
        if (level != current_level) {
            current_level = level;
            is_first_elem = 1;
        } else {
            is_first_elem = 0;
        }

        // Apply the function to the node
        applyf(node->item, current_level, is_first_elem);

        // Enqueue the left and right children with the next level
        if (node->left) {
            enqueue(queue, node->left, level + 1);
        }
        if (node->right) {
            enqueue(queue, node->right, level + 1);
        }
    }

    // Free the queue (optional, but recommended to avoid memory leaks)
    free(queue->nodes);
    free(queue);
}
