#ifndef STDLIB_H
#define STDLIB_H

#include <stddef.h>

/* String conversion functions */
int ft_atoi(const char *str);
long ft_atol(const char *str);
long long ft_atoll(const char *str);
double ft_atof(const char *str);

/* Memory allocation functions */
void *ft_malloc(size_t size);
void *ft_calloc(size_t count, size_t size);
void *ft_realloc(void *ptr, size_t size);
void ft_free(void *ptr);

#endif /* STDLIB_H */