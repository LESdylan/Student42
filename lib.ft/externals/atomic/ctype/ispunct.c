/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ispunct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:27:50 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:27:52 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ispunct(char c) {
    return ((c > 32 && c <= 126) && !(c >= '0' && c <= '9') && !(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z'));
}

// Test function
int main() {
    char test_char = '!';
    printf("ispunct('%c') = %d\n", test_char, ispunct(test_char)); // Should print 1
    test_char = 'A';
    printf("ispunct('%c') = %d\n", test_char, ispunct(test_char)); // Should print 0
    test_char = '1';
    printf("ispunct('%c') = %d\n", test_char, ispunct(test_char)); // Should print 0
    return 0;
}
