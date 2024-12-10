/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:47 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:41:00 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n) {
    const unsigned char *ptr = (const unsigned char *)s;
    while (n--) {
        if (*ptr == (unsigned char)c) {
            return (void *)ptr;
        }
        ptr++;
    }
    return NULL;
}

// Test function
#include <stdio.h>

int main() {
    char buffer[] = "Hello, World!";
    char *result = (char *)ft_memchr(buffer, 'W', 13);

    if (result) {
        printf("Found: %s\n", result); // Should print "World!"
    } else {
        printf("Not found.\n");
    }

    return 0;
}
