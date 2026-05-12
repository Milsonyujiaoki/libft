#include "../../include/ctype.h"

int ft_isalnum(int ch){
	return ((ch>='A' && 'Z'>=ch)||
			 (ch>='a'&& 'z'>=ch)||
			 (ch>='0' && '9'>=ch));
}
