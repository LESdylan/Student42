#ifndef FT_STRING_H
#define FT_STRING_H

#include <stddef.h>

size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
size_t  ft_strlcat(char *dest, const char *src, size_t size);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
char    *ft_substr(const char *s, unsigned int start, size_t len);
char    *ft_strjoin(const char *s1, const char *s2);
char    **ft_split(const char *s, char c);
char    *ft_strtrim(const char *s1, const char *set);
char    *ft_strmapi(const char *s, char (*f)(unsigned int, char));

#endif
