/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:45 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:39:04 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memcpy(void *dest, const void *src, size_t n) {
    if (!dest || !src) return NULL;

    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }

    return dest;
}

// Test function
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, World!";
    char dest[20];

    ft_memcpy(dest, src, strlen(src) + 1); // Include the null terminator
    printf("Copied string: %s\n", dest); // Should print "Hello, World!"

    return 0;
}
