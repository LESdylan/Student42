#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 16

// Function to print the hexadecimal representation of a byte
void print_hex(unsigned char byte)
{
    char hex[3];
    snprintf(hex, sizeof(hex), "%02x", byte);
    write(1, hex, 2);
}

// Function to print the ASCII representation of a byte
void print_ascii(unsigned char byte)
{
    if (byte >= 32 && byte <= 126)
        write(1, &byte, 1);
    else
        write(1, ".", 1);
}

// Function to handle the `-C` option and print the hexdump
void print_hexdump(int fd, int is_canonical)
{
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    size_t offset = 0;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        // Print the offset in hexadecimal
        dprintf(1, "%08lx  ", offset);

        // Print the hexadecimal values
        for (size_t i = 0; i < bytes_read; i++)
        {
            print_hex(buffer[i]);
            if (i != bytes_read - 1)
                write(1, " ", 1);  // Space between hexadecimal bytes
        }

        // Fill remaining spaces if less than 16 bytes are read
        for (size_t i = bytes_read; i < BUFFER_SIZE; i++)
        {
            write(1, "   ", 3);  // Three spaces for alignment
        }

        // Print the ASCII representation if the `-C` option is set
        if (is_canonical)
        {
            write(1, "  ", 2);  // Separator between hex and ASCII columns
            for (size_t i = 0; i < bytes_read; i++)
            {
                print_ascii(buffer[i]);
            }
        }

        write(1, "\n", 1);  // Newline after each row
        offset += bytes_read;
    }

    if (bytes_read == (size_t)-1)
    {
        write(2, strerror(errno), strlen(strerror(errno)));
        write(2, "\n", 1);
    }
}

// Function to parse command-line arguments
int parse_arguments(int argc, char **argv)
{
    int is_canonical = 0;
    int fd;

    if (argc == 1)
    {
        write(2, "File name missing.\n", 19);
        return 1;
    }

    if (argc > 3)
    {
        write(2, "Too many arguments.\n", 20);
        return 1;
    }

    // Check if -C is present in the arguments
    if (argc == 3 && strcmp(argv[1], "-C") == 0)
    {
        is_canonical = 1;
    }

    // Open the file
    fd = open(argv[argc - 1], O_RDONLY);
    if (fd == -1)
    {
        write(2, "Cannot read file.\n", 18);
        return 1;
    }

    // Call the function to print the hexdump
    print_hexdump(fd, is_canonical);

    close(fd);
    return 0;
}

int main(int argc, char **argv)
{
    return parse_arguments(argc, argv);
}
