/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:28:20 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:28:22 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int isupper(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Test function
int main() {
    char test_char = 'A';
    printf("isupper('%c') = %d\n", test_char, isupper(test_char)); // Should print 1
    test_char = 'a';
    printf("isupper('%c') = %d\n", test_char, isupper(test_char)); // Should print 0
    test_char = 'Z';
    printf("isupper('%c') = %d\n", test_char, isupper(test_char)); // Should print 1
    return 0;
}
