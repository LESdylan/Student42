/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:31:37 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 11:31:39 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putstr_fd(const char *str, int fd) {
    if (!str) return; // Handle null input
    while (*str) {
        write(fd, str, 1);
        str++;
    }
}

// Test function
int main() {
    putstr_fd("Hello, File Descriptor!\n", 1); // Writes to stdout
    putstr_fd("This is an error message!\n", 2); // Writes to stderr
    return 0;
}
