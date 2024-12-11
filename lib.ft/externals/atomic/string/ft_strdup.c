/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:52:08 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:52:12 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char *ft_strdup(const char *str) {
    size_t len = strlen(str) + 1;
    char *dup = (char *)malloc(len);
    if (!dup) {
        return NULL;
    }
    memcpy(dup, str, len);
    return dup;
}

// Test function
int main() {
    const char *original = "Hello, World!";
    char *duplicate = ft_strdup(original);

    if (duplicate) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
