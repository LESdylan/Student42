/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:06:59 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:46:15 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strchr(const char *str, int c) {
    while (*str) {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

// Test function
int main() {
    const char *str = "Hello, World!";
    char *result = ft_strchr(str, 'W');

    if (result) {
        printf("Character found: %s\n", result);
    } else {
        printf("Character not found\n");
    }

    return 0;
}

