/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:23:40 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 12:23:45 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

FILE *fopen(const char *filename, const char *mode) {
    int flags = 0;
    FILE *file = NULL;
    
    if (mode[0] == 'r') {
        flags = O_RDONLY;  // Open for reading only
    } else if (mode[0] == 'w') {
        flags = O_WRONLY | O_CREAT | O_TRUNC;  // Open for writing, create if not exists, truncate if exists
    } else if (mode[0] == 'a') {
        flags = O_WRONLY | O_CREAT | O_APPEND; // Open for writing, create if not exists, append
    }
    
    int fd = open(filename, flags, 0644);
    if (fd == -1) {
        return NULL;  // Error opening file
    }

    file = (FILE *)malloc(sizeof(FILE));
    if (file == NULL) {
        close(fd);
        return NULL;  // Memory allocation error
    }

    file->fd = fd;
    return file;
}
