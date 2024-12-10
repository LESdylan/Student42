/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:54:24 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:54:26 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char *ft_strtok(char *str, const char *delim) {
    static char *last = NULL;
    if (str) {
        last = str;  // First call, set the string to be tokenized
    }
    
    if (!last) {
        return NULL;  // If last is NULL, there's no string to tokenize
    }

    // Skip leading delimiters
    while (*last && strchr(delim, *last)) {
        last++;
    }

    if (*last == '\0') {
        return NULL;  // No more tokens
    }

    char *start = last;
    // Find the next delimiter
    while (*last && !strchr(delim, *last)) {
        last++;
    }

    if (*last) {
        *last = '\0';  // Replace delimiter with null-terminator
        last++;
    }

    return start;
}

// Test function
int main() {
    char str[] = "Hello, World! This is a test.";
    char *token = ft_strtok(str, " ,!");

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = ft_strtok(NULL, " ,!");
    }

    return 0;
}
