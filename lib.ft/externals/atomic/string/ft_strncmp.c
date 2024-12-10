/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:07:11 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:47:43 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strncmp(const char *s1, const char *s2, size_t n) {
    while (n-- && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (n == (size_t)-1) ? 0 : *(unsigned char *)s1 - *(unsigned char *)s2;
}

// Test function
int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, World!";
    
    if (ft_strncmp(str1, str2, 5) == 0) {
        printf("First 5 characters are equal\n");
    } else {
        printf("First 5 characters are not equal\n");
    }

    return 0;
}
