/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:31:28 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:31:30 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putnbr_fd(int n, int fd) {
    char buffer[12]; // Enough to hold "-2147483648\0"
    int i = 0;

    if (n == -2147483648) {
        write(fd, "-2147483648", 11);
        return;
    }

    if (n < 0) {
        write(fd, "-", 1);
        n = -n;
    }

    // Convert the number to a string
    do {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    } while (n > 0);

    // Write the number in reverse order
    while (i > 0) {
        write(fd, &buffer[--i], 1);
    }
}

// Test function
int main() {
    putnbr_fd(12345, 1);   // Writes "12345" to stdout
    write(1, "\n", 1);     // Writes a newline
    putnbr_fd(-6789, 1);   // Writes "-6789" to stdout
    write(1, "\n", 1);     // Writes a newline
    return 0;
}
