#include <stdio.h>
#include "../../include/ctype.h"

int main(void){
	int teste[] = {'A', '!', 128, 255, -1, 0,127,'z','?'};
	int tamanho = sizeof(teste) / sizeof(teste[0]);

	for(int i = 0; i < tamanho; i++){
    	if(ft_isascii(teste[i])){
        	// %3d alinha os números, %c mostra o char
        	printf("Decimal %3d: [ %c ] É ascii.\n", teste[i], (teste[i] < 32 ? ' ' : teste[i]));
    	} else {
        	printf("Decimal %3d: [ %c ] NÃO é ascii.\n", teste[i], ' ');
    }
}
		
	return 0;
}
