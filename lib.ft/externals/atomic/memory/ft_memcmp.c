/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:49 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:41:10 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    while (n--) {
        if (*p1 != *p2) {
            return *p1 - *p2;
        }
        p1++;
        p2++;
    }
    return 0;
}

// Test function
#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "abcdef";
    char s2[] = "abcdez";

    printf("Comparison result: %d\n", ft_memcmp(s1, s2, 5)); // Should print 0
    printf("Comparison result: %d\n", ft_memcmp(s1, s2, 6)); // Should print a negative value

    return 0;
}
