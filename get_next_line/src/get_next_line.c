/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:59:14 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 15:20:45 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static char *str_join(char *s1, const char *s2)
{
    size_t len1 = (s1) ? strlen(s1) : 0;  // Check for NULL s1
    size_t len2 = strlen(s2);
    char *result = realloc(s1, len1 + len2 + 1); // realloc to extend the existing string

    if (!result)
    {
        free(s1);  // Free the original string if realloc fails
        return NULL;
    }

    // Copy the second string to the end of the first
    memcpy(result + len1, s2, len2 + 1);  // memcpy to avoid manual looping
    return result;
}

static char *get_line(char *str)
{
    if (!str) 
        return NULL;

    size_t i = 0;
    while (str[i] != '\n' && str[i] != '\0')
        i++;

    char *line = malloc(i + 1);  // Allocate memory for the line
    if (!line) 
        return NULL;

    memcpy(line, str, i);  // Copy up to the newline or end
    line[i] = '\0';  // Null-terminate the line
    return line;
}

static char *get_remaining(char *str)
{
    if (!str)
        return NULL;

    size_t i = 0;
    while (str[i] != '\n' && str[i] != '\0')
        i++;

    // If no newline is found, return NULL and free the string
    if (str[i] == '\0')
    {
        free(str);
        return NULL;
    }

    // Skip the newline character
    char *remaining = strdup(str + i + 1);  // strdup copies the remaining part after the newline
    free(str);  // Free the original string
    return remaining;
}

int get_next_line(int fd, char **line)
{
    static char *buffer = NULL;  // Static buffer to retain data between function calls
    char tmp[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return -1;

    *line = NULL;
    while ((bytes_read = read(fd, tmp, BUFFER_SIZE)) > 0)
    {
        tmp[bytes_read] = '\0';  // Null-terminate the read data
        buffer = str_join(buffer, tmp);  // Concatenate the new data to the buffer

        if (!buffer)  // Check if allocation failed
            return -1;

        // If we've found a newline, break out of the loop
        if (strchr(buffer, '\n'))
            break;
    }

    if (bytes_read < 0)  // If there was an error reading
        return -1;

    // Get the line from the buffer
    *line = get_line(buffer);
    if (!*line)
        return -1;

    // Update the buffer to contain the remaining part after the newline
    buffer = get_remaining(buffer);

    // If the line is empty at the end of the file, return 0 (EOF)
    if (bytes_read == 0 && *line && **line == '\0')
    {
        free(*line);  // Free the empty line
        *line = NULL;
        return 0;
    }

    return (bytes_read > 0) ? 1 : 0;  // Return 1 for success, 0 for EOF
}
