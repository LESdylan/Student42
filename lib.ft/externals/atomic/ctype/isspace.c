/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isspace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:28:07 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:28:08 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int isspace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

// Test function
int main() {
    char test_char = ' ';
    printf("isspace('%c') = %d\n", test_char, isspace(test_char)); // Should print 1
    test_char = '\n';
    printf("isspace('%c') = %d\n", test_char, isspace(test_char)); // Should print 1
    test_char = 'A';
    printf("isspace('%c') = %d\n", test_char, isspace(test_char)); // Should print 0
    return 0;
}
