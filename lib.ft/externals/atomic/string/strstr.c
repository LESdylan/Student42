/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:54:14 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:54:15 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)haystack;  // If needle is empty, return haystack
    }

    for (size_t i = 0; haystack[i] != '\0'; i++) {
        size_t j = 0;
        while (haystack[i + j] == needle[j]) {
            if (needle[j + 1] == '\0') {
                return (char *)(haystack + i);  // Match found, return pointer to the start
            }
            j++;
        }
    }

    return NULL;  // Needle not found
}

// Test function
int main() {
    const char *haystack = "Hello, World!";
    const char *needle = "World";
    char *result = ft_strstr(haystack, needle);

    if (result) {
        printf("Found substring: %s\n", result);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
