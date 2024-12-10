/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:19:48 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 16:34:26 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print data of each list element (used for ft_list_foreach)
void print_data(void *data) {
    printf("%s -> ", (char *)data);
}

// Comparison function for ft_sorted_list_insert, ft_list_foreach_if, and ft_list_find
int cmp(void *data1, void *data2) {
    return strcmp((char *)data1, (char *)data2);
}

// Comparison function for integers, used for sorted list operations
int compare_ints(void *data1, void *data2) {
    return (*(int *)data1 - *(int *)data2);
}

// Free function for ft_list_remove_if
void free_fct(void *data) {
    free(data);
}

// Function to print the list
void print_list(t_list *list) {
    while (list != NULL) {
        printf("%s -> ", (char *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

int main() {
    // Section 1: Reversal Functions
    printf("=== Section 1: Reversal Functions ===\n");
    t_list *list = ft_create_elem("First");
    ft_list_push_front(&list, "Second");
    ft_list_push_front(&list, "Third");

    printf("Original list:\n");
    print_list(list);

    ft_list_reverse(&list);
    printf("List after ft_list_reverse:\n");
    print_list(list);

    ft_list_reverse_fun(list);
    printf("List after ft_list_reverse_fun:\n");
    print_list(list);
    printf("\n");

    // Section 2: Foreach and Foreach If Functions
    printf("=== Section 2: Foreach Functions ===\n");
    t_list *list2 = ft_create_elem("First element");
    ft_list_push_front(&list2, "Second element");
    ft_list_push_front(&list2, "Third element");

    printf("Original list:\n");
    print_list(list2);

    printf("Using ft_list_foreach:\n");
    ft_list_foreach(list2, print_data);
    printf("NULL\n");

    char *reference = "Second element";
    printf("Using ft_list_foreach_if (reference = '%s'):\n", reference);
    ft_list_foreach_if(list2, print_data, reference, cmp);
    printf("NULL\n\n");

    // Section 3: Find and Remove Functions
    printf("=== Section 3: Find and Remove Functions ===\n");
    t_list *found = ft_list_find(list2, reference, cmp);
    if (found != NULL) {
        printf("Found element: %s\n", (char *)found->data);
    } else {
        printf("Element not found\n");
    }

    ft_list_remove_if(&list2, reference, cmp, free_fct);
    printf("List after ft_list_remove_if:\n");
    print_list(list2);
    printf("\n");

    // Section 4: Merge Functions
    printf("=== Section 4: Merge Functions ===\n");
    t_list *list3 = ft_create_elem("First element");
    ft_list_push_front(&list3, "Second element");

    t_list *list4 = ft_create_elem("Third element");
    ft_list_push_front(&list4, "Fourth element");

    printf("List 1 before merge:\n");
    print_list(list3);
    printf("List 2 before merge:\n");
    print_list(list4);

    ft_list_merge(&list3, list4);
    printf("List 1 after ft_list_merge:\n");
    print_list(list3);
    printf("\n");

    // Section 5: Sorted List Functions
    printf("=== Section 5: Sorted List Functions ===\n");
    t_list *list5 = NULL;
    int a = 3, b = 1, c = 2;

    ft_sorted_list_insert(&list5, &a, compare_ints);
    ft_sorted_list_insert(&list5, &b, compare_ints);
    ft_sorted_list_insert(&list5, &c, compare_ints);

    printf("Sorted list after ft_sorted_list_insert:\n");
    print_list(list5);

    t_list *list6 = NULL;
    t_list *list7 = NULL;

    int x = 1, y = 3, z = 5;
    int p = 2, q = 4, r = 6;

    ft_sorted_list_insert(&list6, &x, compare_ints);
    ft_sorted_list_insert(&list6, &y, compare_ints);
    ft_sorted_list_insert(&list6, &z, compare_ints);

    ft_sorted_list_insert(&list7, &p, compare_ints);
    ft_sorted_list_insert(&list7, &q, compare_ints);
    ft_sorted_list_insert(&list7, &r, compare_ints);

    printf("List 1 (sorted):\n");
    print_list(list6);
    printf("List 2 (sorted):\n");
    print_list(list7);

    ft_sorted_list_merge(&list6, list7, compare_ints);
    printf("Merged list after ft_sorted_list_merge:\n");
    print_list(list6);

    return 0;
}
