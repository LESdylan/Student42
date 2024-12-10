/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscntrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:26:41 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:26:43 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int iscntrl(char c) {
    return ((c >= 0 && c <= 31) || c == 127);
}

// Test function
int main() {
    char test_char = '\n';
    printf("iscntrl('%c') = %d\n", test_char, iscntrl(test_char)); // Should print 1
    test_char = 'a';
    printf("iscntrl('%c') = %d\n", test_char, iscntrl(test_char)); // Should print 0
    return 0;
}
