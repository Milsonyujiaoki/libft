#include <stdio.h>
#include "../../include/string.h"

int main(void){
	char msg[20] = "Fala pessoal!\n";
	char src[20]="Tudo bem com voces?";
	ft_strcat(msg,src);
	
	printf("ft_strcat: %s\n",msg);
	return 0;
}
