/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:47:17 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:47:23 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char *ft_strmapi(const char *s, char (*f)(unsigned int, char)) {
    size_t len = strlen(s);
    char *result = (char *)malloc(len + 1);

    if (!result) return NULL;

    for (unsigned int i = 0; i < len; i++) {
        result[i] = f(i, s[i]);
    }
    result[len] = '\0';
    return result;
}

// Test function
#include <stdio.h>
char to_uppercase(unsigned int index, char c) {
    if (index % 2 == 0) {
        return c - 32;  // Convert to uppercase
    }
    return c;
}

int main() {
    const char *str = "hello world";
    char *result = ft_strmapi(str, to_uppercase);

    if (result) {
        printf("Mapped string: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
