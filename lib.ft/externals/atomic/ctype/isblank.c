/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isblank.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:26:36 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:26:38 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int isblank(char c) {
    return (c == ' ' || c == '\t');
}

// Test function
int main() {
    char test_char = ' ';
    printf("isblank('%c') = %d\n", test_char, isblank(test_char)); // Should print 1
    test_char = '\t';
    printf("isblank('%c') = %d\n", test_char, isblank(test_char)); // Should print 1
    test_char = 'a';
    printf("isblank('%c') = %d\n", test_char, isblank(test_char)); // Should print 0
    return 0;
}
