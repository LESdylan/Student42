/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:50:02 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:50:13 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr_base_recursive(int nbr, char *base, int base_len) {
    if (nbr < 0) {
        write(1, "-", 1);  // Handle negative numbers
        nbr = -nbr;
    }
    
    if (nbr >= base_len) {
        ft_putnbr_base_recursive(nbr / base_len, base, base_len); // Recurse
    }

    write(1, &base[nbr % base_len], 1); // Print the character corresponding to the digit
}

int ft_strlen(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void ft_putnbr_base(int nbr, char *base) {
    int base_len = ft_strlen(base);
    
    if (base_len < 2) {
        return;  // Invalid base (base must be at least 2)
    }

    // Check for duplicate characters in base string (e.g., "0123" is invalid)
    for (int i = 0; i < base_len; i++) {
        for (int j = i + 1; j < base_len; j++) {
            if (base[i] == base[j]) {
                return;  // Invalid base: characters are repeated
            }
        }
    }

    ft_putnbr_base_recursive(nbr, base, base_len);
}
int main() {
    char *hex_base = "0123456789abcdef";
    int number = -255;

    ft_putnbr_base(number, hex_base);  // Output: -ff (in base 16)
    write(1, "\n", 1);

    char *bin_base = "01";
    number = 5;
    ft_putnbr_base(number, bin_base);  // Output: 101 (in base 2)
    write(1, "\n", 1);

    return 0;
}
