/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:29:45 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:29:46 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void *memset(void *str, int c, size_t n) {
    unsigned char *p = (unsigned char *)str;
    for (size_t i = 0; i < n; i++) {
        p[i] = (unsigned char)c;
    }
    return str;
}

// Test function
int main() {
    char data[20] = "Hello, World!";
    memset(data, '*', 5);
    printf("data after memset: %s\n", data); // Should print "***** World!"
    return 0;
}
