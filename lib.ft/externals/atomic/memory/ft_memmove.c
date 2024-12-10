/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:54 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:41:26 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memmove(void *dest, const void *src, size_t n) {
    if (!dest || !src) return NULL;

    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    if (d < s) {
        while (n--) {
            *d++ = *s++;
        }
    } else {
        d += n;
        s += n;
        while (n--) {
            *(--d) = *(--s);
        }
    }

    return dest;
}

// Test function
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[] = "Hello, World!";
    ft_memmove(buffer + 7, buffer, 5); // Overlapping copy
    printf("Result: %s\n", buffer);   // Should print "Hello, Hello!"

    return 0;
}
