/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isgraph.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:27:33 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:27:34 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int isgraph(char c) {
    return (c > 32 && c <= 126);
}

// Test function
int main() {
    char test_char = 'A';
    printf("isgraph('%c') = %d\n", test_char, isgraph(test_char)); // Should print 1
    test_char = ' ';
    printf("isgraph('%c') = %d\n", test_char, isgraph(test_char)); // Should print 0
    test_char = '!';
    printf("isgraph('%c') = %d\n", test_char, isgraph(test_char)); // Should print 1
    return 0;
}
