#include <stdio.h>
#include "../../include/string.h"

int main(void) {
    char texto[] = "Salve Galera!!!";

    char destino[50];

    ft_strcpy(destino, texto);

    printf("ft_strcpy: %s\n", destino);

    return 0;
}
