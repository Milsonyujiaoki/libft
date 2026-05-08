#include <stdio.h>
#include "../include/string.h"

int main(void) {
    char texto[] = "Hello World";

    printf("Tamanho: %zu\n", ft_strlen(texto));

    char destino[20];

    ft_memcpy(destino, texto, ft_strlen(texto) + 1);

    printf("Copia: %s\n", destino);

    return 0;
}
