#include <string.h>
#include <stdlib.h>

char *ft_strndup(const char *src, size_t count){
    // TODO: implement with ft_malloc when available
     size_t len = ft_strlen(src);
     if (len > count) {
         len = count;
     }
     char *new_str = malloc(len + 1);
     if (new_str == NULL) {
         return NULL;
     }
     ft_memcpy(new_str, src, len);
     new_str[len] = '\0';
     return new_str;
    (void)src;
    (void)count;
    return NULL;
}