#ifndef FT_IO_H
#define FT_IO_H

#include <unistd.h>

void ft_putchar_fd(char c, int fd);
void ft_putnbr_fd(int n, int fd);
void ft_putstr_fd(const char *s, int fd);

#endif
