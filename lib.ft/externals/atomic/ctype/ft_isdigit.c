/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:26:47 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:26:49 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int isdigit(char c) {
    return (c >= '0' && c <= '9');
}

// Test function
int main() {
    char test_char = '5';
    printf("isdigit('%c') = %d\n", test_char, isdigit(test_char)); // Should print 1
    test_char = 'a';
    printf("isdigit('%c') = %d\n", test_char, isdigit(test_char)); // Should print 0
    return 0;
}
