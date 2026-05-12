#include <stdio.h>
#include "../../include/ctype.h"

int main(void){

	char teste[] = {'A', '5', '!', 'z', ' '};
	int tamanho = sizeof(teste) / sizeof(teste[0]);

	for (int i=0; i<tamanho;i++) {
		if(ft_isalnum(teste[i])){
			printf("'%c' é alfanumérico.\n", teste[i]);
		} else{
			printf("'%c' NÃO é alfanumérico.\n", teste[i]);
		}
	}
	
	return 0;
}
