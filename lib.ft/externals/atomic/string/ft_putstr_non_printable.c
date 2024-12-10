/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:46:58 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:47:08 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr_non_printable(char *str) {
    char hex_digits[] = "0123456789abcdef";
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 126) {
            // Printable characters, just write them
            write(1, &str[i], 1);
        } else {
            // Non-printable characters, print \x and then the hex value
            write(1, "\\x", 2);
            write(1, &hex_digits[(str[i] / 16) % 16], 1); // High nibble
            write(1, &hex_digits[str[i] % 16], 1); // Low nibble
        }
        i++;
    }
}
