/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:27:40 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:27:42 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int isprint(char c) {
    return (c >= 32 && c <= 126);
}

// Test function
int main() {
    char test_char = 'A';
    printf("isprint('%c') = %d\n", test_char, isprint(test_char)); // Should print 1
    test_char = ' ';
    printf("isprint('%c') = %d\n", test_char, isprint(test_char)); // Should print 1
    test_char = '\n';
    printf("isprint('%c') = %d\n", test_char, isprint(test_char)); // Should print 0
    return 0;
}
