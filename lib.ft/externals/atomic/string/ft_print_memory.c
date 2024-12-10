/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:46:50 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:46:56 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_memory(const void *addr, size_t size) {
    unsigned char *ptr = (unsigned char *)addr;
    size_t i, j;
    char hex_digits[] = "0123456789abcdef";
    
    for (i = 0; i < size; i += 16) {
        // Print the address
        char address[18]; // Format: "0xXXXXXXXX\n"
        snprintf(address, sizeof(address), "0x%08lx: ", (unsigned long)(ptr + i));
        write(1, address, 10);

        // Print the hex bytes
        for (j = 0; j < 16 && i + j < size; ++j) {
            write(1, &hex_digits[(ptr[i + j] / 16) % 16], 1);
            write(1, &hex_digits[ptr[i + j] % 16], 1);
            if (j % 2) {
                write(1, " ", 1); // Add space every two bytes
            }
        }

        // Fill the remaining space with spaces if less than 16 bytes
        for (; j < 16; ++j) {
            write(1, "  ", 2);
            if (j % 2) {
                write(1, " ", 1);
            }
        }

        // Print ASCII characters
        for (j = 0; j < 16 && i + j < size; ++j) {
            if (ptr[i + j] >= 32 && ptr[i + j] <= 126) {
                write(1, &ptr[i + j], 1);
            } else {
                write(1, ".", 1);  // Non-printable chars are represented as '.'
            }
        }

        // Newline after each line of memory output
        write(1, "\n", 1);
    }
}
