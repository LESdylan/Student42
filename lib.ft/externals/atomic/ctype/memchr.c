/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:28:35 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:29:13 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void *memchr(const void *str, int c, size_t n) {
    const unsigned char *p = (const unsigned char *)str;
    for (size_t i = 0; i < n; i++) {
        if (p[i] == (unsigned char)c) {
            return (void *)(p + i);
        }
    }
    return NULL;
}

// Test function
int main() {
    char data[] = "Hello, World!";
    char *result = memchr(data, 'W', sizeof(data));
    if (result) {
        printf("Found 'W' at position: %ld\n", result - data);
    } else {
        printf("'W' not found\n");
    }
    return 0;
}
