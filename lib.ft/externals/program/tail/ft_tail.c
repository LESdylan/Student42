/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:48:53 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 13:48:57 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 1024  // Buffer size to read from files

// Function to display the last N bytes of a file
void ft_tail(int fd, int num_bytes)
{
    char buf[BUF_SIZE];
    off_t file_size;
    ssize_t bytes_read;
    off_t offset;

    // Get the size of the file using fstat
    file_size = lseek(fd, 0, SEEK_END);
    if (file_size == -1)
    {
        write(2, "Error getting file size\n", 24);
        return;
    }

    // If requested bytes are greater than file size, adjust num_bytes
    if (num_bytes > file_size)
    {
        num_bytes = file_size;
    }

    // Move to the point where we need to start reading from the end of the file
    offset = file_size - num_bytes;
    if (lseek(fd, offset, SEEK_SET) == -1)
    {
        write(2, "Error seeking file\n", 19);
        return;
    }

    // Read the file from the offset and write to standard output
    while ((bytes_read = read(fd, buf, BUF_SIZE)) > 0)
    {
        write(1, buf, bytes_read);
    }

    // Handle reading errors
    if (bytes_read == -1)
    {
        write(2, "Error reading file\n", 19);
    }
}

// Function to handle command line arguments and file reading
int parse_arguments(int argc, char **argv)
{
    int num_bytes = 10; // Default behavior: display the last 10 bytes
    int i = 1;
    int fd;

    // If the first argument is -c, parse the number of bytes
    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
    {
        if (argc < 3)
        {
            write(2, "Missing argument for -c option\n", 31);
            return 1;
        }

        num_bytes = atoi(argv[2]); // Convert the string to integer for the byte count
        i = 3; // Start processing files after the option
    }

    if (argc == i) // No files specified, read from stdin
    {
        ft_tail(0, num_bytes); // 0 refers to stdin
        return 0;
    }

    // Process each file given as argument
    for (; i < argc; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            // Handle error opening file
            if (errno == ENOENT)
                write(2, "Error: file not found\n", 21);
            else if (errno == EACCES)
                write(2, "Error: permission denied\n", 25);
            else
                write(2, "Error opening file\n", 19);
            continue;
        }

        ft_tail(fd, num_bytes); // Display the last 'num_bytes' bytes from the file
        close(fd); // Close the file after processing
    }

    return 0;
}

int main(int argc, char **argv)
{
    return parse_arguments(argc, argv);
}
