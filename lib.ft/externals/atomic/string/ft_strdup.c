/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:07:02 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:46:45 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char *ft_strdup(const char *str) {
    size_t len = strlen(str);
    char *dup = (char *)malloc(len + 1);
    if (!dup) return NULL;
    strcpy(dup, str);
    return dup;
}

// Test function
#include <stdio.h>
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
