#include <string.h>
#include <stdlib.h>

char *ft_strdup(const char *src)
{
    // TODO: implement with ft_malloc when available
     size_t len = ft_strlen(src) + 1;
     char *new_str = malloc(len);
     if (new_str == NULL) {
         return NULL;
     }
     ft_memcpy(new_str, src, len);
     return new_str;
    (void)src;
    return NULL;
}