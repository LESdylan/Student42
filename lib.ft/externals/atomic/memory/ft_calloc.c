/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:31 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:40:50 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void *ft_calloc(size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;
    void *ptr = malloc(total_size);
    if (!ptr) return NULL;
    ft_bzero(ptr, total_size);
    return ptr;
}

// Test function
#include <stdio.h>

int main() {
    int *arr = (int *)ft_calloc(5, sizeof(int));

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]); // Should print "0 0 0 0 0"
    }
    printf("\n");

    free(arr);
    return 0;
}
