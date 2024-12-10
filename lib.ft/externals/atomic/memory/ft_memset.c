/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:56 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:41:33 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memset(void *s, int c, size_t n) {
    unsigned char *ptr = (unsigned char *)s;
    while (n--) {
        *ptr++ = (unsigned char)c;
    }
    return s;
}

// Test function
#include <stdio.h>

int main() {
    char buffer[10] = "abcdefghi";
    ft_memset(buffer, 'x', 5);

    printf("Result: %s\n", buffer); // Should print "xxxxxefghi"

    return 0;
}
