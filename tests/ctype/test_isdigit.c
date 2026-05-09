#include <stdio.h>
#include "../../include/ctype.h"

int main(void)
{
    printf("'0': %d\n", ft_isdigit('0'));
    printf("'5': %d\n", ft_isdigit('5'));
    printf("'9': %d\n", ft_isdigit('9'));

    printf("'a': %d\n", ft_isdigit('a'));
    printf("'@': %d\n", ft_isdigit('@'));
    printf("' ': %d\n", ft_isdigit(' '));

    return 0;
}
