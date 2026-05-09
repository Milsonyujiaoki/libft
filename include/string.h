#ifndef MINI_STRING_H
#define MINI_STRING_H

#include <stddef.h>

size_t ft_strlen(const char *str);

void *ft_memcpy(void *dest, const void *src, size_t n);

char *ft_strcpy(char *dest, const char *src);

char *ft_strcpy_v2(char *dest, const char *src);

char *ft_strcat(char *dest, const char *src);


#endif
