/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:07:15 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:48:53 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strrchr(const char *str, int c) {
    char *last_occurrence = NULL;

    while (*str) {
        if (*str == (char)c) {
            last_occurrence = (char *)str;
        }
        str++;
    }

    return last_occurrence;
}

// Test function
int main() {
    const char *str = "Hello, World!";
    char *result = ft_strrchr(str, 'o');

    if (result) {
        printf("Last occurrence of 'o': %s\n", result);
    } else {
        printf("'o' not found.\n");
    }

    return 0;
}
