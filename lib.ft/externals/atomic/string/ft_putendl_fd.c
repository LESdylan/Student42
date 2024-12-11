/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:41:01 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 18:41:27 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // for write
#include <string.h>  // for strlen

void ft_putendl_fd(char const *s, int fd)
{
    // Check if the string is not NULL
    if (s)
    {
        // Use write(2) to output the string to the file descriptor
        write(fd, s, strlen(s));

        // Output a newline character after the string
        write(fd, "\n", 1);
    }
}

#include <stdio.h>

int main()
{
    char str[] = "Hello, World!";

    // Write string followed by newline to standard output (fd = 1)
    ft_putendl_fd(str, 1);  // Should print "Hello, World!" followed by a newline to the terminal

    // Write string followed by newline to standard error (fd = 2)
    ft_putendl_fd(str, 2);  // Should print "Hello, World!" followed by a newline to stderr

    return 0;
}
