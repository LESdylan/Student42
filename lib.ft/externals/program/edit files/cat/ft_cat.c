/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:42:45 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:42:47 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 4096  // Buffer size set to 4KB, which is a little less than 30KB

// Function to display the content of a file or standard input
void ft_cat(int fd)
{
    char buf[BUF_SIZE];
    ssize_t bytes_read;

    // Read the file content into the buffer and write it to stdout
    while ((bytes_read = read(fd, buf, BUF_SIZE)) > 0)
    {
        write(1, buf, bytes_read);  // Write to standard output
    }

    // Check if there was an error during the read operation
    if (bytes_read == -1)
    {
        write(2, "Error reading file\n", 19);
    }
}

int main(int argc, char **argv)
{
    int fd;
    int i;

    // If no arguments, read from standard input
    if (argc == 1)
    {
        ft_cat(0);  // 0 is the file descriptor for standard input
    }
    else
    {
        // Process each file passed as argument
        for (i = 1; i < argc; i++)
        {
            fd = open(argv[i], O_RDONLY);
            if (fd == -1)
            {
                // Handle error for unable to open the file
                if (errno == ENOENT)
                    write(2, "Error: file not found\n", 21);
                else if (errno == EACCES)
                    write(2, "Error: permission denied\n", 25);
                else
                    write(2, "Error opening file\n", 19);
            }
            else
            {
                ft_cat(fd);  // Read and print the file content
                close(fd);   // Close the file after processing
            }
        }
    }
    return 0;
}
