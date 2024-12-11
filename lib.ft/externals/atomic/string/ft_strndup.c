/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:52:56 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:52:58 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char *ft_strndup(const char *str, size_t n) {
    size_t len = strnlen(str, n);  // Ensure we don't go beyond 'n'
    char *dup = (char *)malloc(len + 1);
    if (!dup) {
        return NULL;
    }
    strncpy(dup, str, len);
    dup[len] = '\0';
    return dup;
}

// Test function
int main() {
    const char *original = "Hello, World!";
    char *duplicate = ft_strndup(original, 5);

    if (duplicate) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
