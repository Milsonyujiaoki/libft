#include <stdio.h>
#include "../include/string.h"

int main(void) {
    char texto[] = "Hello World!!!";

    printf("ft_strlen: %zu\n", ft_strlen(texto));

    char destino[20];

    ft_strcpy(destino, texto);

    printf("ft_strcpy: %s\n", destino);

    ft_strcpy_v2(destino, texto);

    printf("ft_strcp_v2y: %s\n", destino);

    ft_memcpy(destino, texto, ft_strlen(texto) + 1);
    
    printf("ft_memcpy: %s\n", destino);

    return 0;
}
