/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:29:31 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:29:36 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void *memmove(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    if (d < s) {
        for (size_t i = 0; i < n; i++) {
            d[i] = s[i];
        }
    } else {
        for (size_t i = n; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    }
    return dest;
}

// Test function
int main() {
    char data[] = "OverlapTest";
    memmove(data + 4, data, 5);
    printf("data after memmove: %s\n", data); // Should print "OverOverlap"
    return 0;
}
