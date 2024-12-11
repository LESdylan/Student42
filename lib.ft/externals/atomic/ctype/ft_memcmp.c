/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:29:16 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:29:23 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;
    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return (p1[i] - p2[i]);
        }
    }
    return 0;
}

// Test function
int main() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";

    printf("memcmp(str1, str2) = %d\n", memcmp(str1, str2, sizeof(str1))); // Should print 0
    printf("memcmp(str1, str3) = %d\n", memcmp(str1, str3, sizeof(str1))); // Should print a negative value
    return 0;
}
