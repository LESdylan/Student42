#ifndef FT_TYPE_H
#define FT_TYPE_H

#include <stddef.h>

size_t  ft_strlen(const char *s);
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
char    *ft_toupper(int c);
char    *ft_tolower(int c);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
size_t  ft_strlcpy(char *dest, const char *src, size_t l);
size_t  ft_strlcat(char *dest, const char *src, size_t l);
char    *ft_strnstr(const char *haystack, const char *needle, size_t n);


#endif