#include<ctype.h>


void ToUpper(char* str) {

	for (int i = 0; *(str + i) != 0; i++) {
		if(islower(*(str + i))){
			*(str + i) = *(str + i) - 32;
		}
	}
}