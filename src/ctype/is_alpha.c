#include "../../include/ctype.h"

int ft_isalpha(int ch){

	return ((ch >='A' && 'Z' >= ch)||(ch >='a' && 'z' >= ch));
}
