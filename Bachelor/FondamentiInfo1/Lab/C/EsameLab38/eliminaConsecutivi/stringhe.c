#include "stringhe.h"


void elimina_consecutivi(char* str) {
	if (str != NULL) {
		int i = 0;
		for (int j = 0; str[j] != 0; j++) {
			if (str[j] != str[j + 1]) {
				i++;
				str[i - 1] = str[j];
			}
		}
		str[i] = '\0';
	}
}
