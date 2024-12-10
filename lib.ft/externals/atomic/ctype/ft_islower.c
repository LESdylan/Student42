/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:26:03 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:26:05 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

// Test function
int main() {
    char test_char = 'g';
    printf("is_lower('%c') = %d\n", test_char, is_lower(test_char)); // Should print 1
    test_char = 'G';
    printf("is_lower('%c') = %d\n", test_char, is_lower(test_char)); // Should print 0
    return 0;
}
