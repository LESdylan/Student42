/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:46:50 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:46:56 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char *ft_strjoin(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *joined = (char *)malloc(len1 + len2 + 1);

    if (!joined) return NULL;
    strcpy(joined, s1);
    strcat(joined, s2);

    return joined;
}

// Test function
#include <stdio.h>
int main() {
    const char *str1 = "Hello, ";
    const char *str2 = "World!";
    char *result = ft_strjoin(str1, str2);

    if (result) {
        printf("Joined string: %s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
