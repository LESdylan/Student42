/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:29 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:40:44 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void ft_bzero(void *s, size_t n) {
    unsigned char *ptr = (unsigned char *)s;
    while (n--) {
        *ptr++ = 0;
    }
}

// Test function
#include <stdio.h>

int main() {
    char buffer[10] = "abcdefghi";
    ft_bzero(buffer, 5);

    // Print buffer content
    for (int i = 0; i < 10; i++) {
        printf("%c", buffer[i] ? buffer[i] : '.'); // '.' for null bytes
    }
    printf("\n"); // Should print ".....fghi"

    return 0;
}
