/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:38:05 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:39:30 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // for write

void ft_putchar_fd(char c, int fd)
{
    // Use write(2) to write the character c to the specified file descriptor fd
    write(fd, &c, 1);
}

int main()
{
    char ch = 'A';

    // Write character 'A' to standard output (fd = 1)
    ft_putchar_fd(ch, 1);  // Should print 'A' to the terminal

    // Write character 'B' to standard error (fd = 2)
    ft_putchar_fd(ch, 2);  // Should print 'B' to stderr (usually the terminal or log)

    return 0;
}
