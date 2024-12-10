/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:07:13 by dylan-soul        #+#    #+#             */
/*   Updated: 2024/12/10 11:48:46 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>  // For NULL

char *ft_strnstr(const char *haystack, const char *needle, size_t len) {
    if (*needle == '\0') {
        return (char *)haystack;
    }

    for (size_t i = 0; i < len && haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0]) {
            size_t j = 0;
            while (haystack[i + j] == needle[j] && (i + j) < len) {
                if (needle[j + 1] == '\0') {
                    return (char *)(haystack + i);
                }
                j++;
            }
        }
    }

    return NULL;  // Needle not found within the first 'len' characters
}

// Test function
#include <stdio.h>
int main() {
    const char *haystack = "Hello, World!";
    const char *needle = "World";
    char *result = ft_strnstr(haystack, needle, 10);

    if (result) {
        printf("Found substring: %s\n", result);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
