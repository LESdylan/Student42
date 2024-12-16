/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:59:44 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 15:12:17 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>  // Add this line to fix the implicit declaration of 'open'
#include <unistd.h>

int main(void)
{
    int fd;
    char buffer[100];

    fd = open("./testing/test_file.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Here you can use read() or any other file handling code
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead < 0)
    {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    buffer[bytesRead] = '\0';  // Null-terminate the string
    printf("Read from file: %s\n", buffer);

    close(fd);
    return 0;
}