#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include <string.h>
# define BUFFER_SIZE 32

int get_next_line(int fd, char **line);

#endif
