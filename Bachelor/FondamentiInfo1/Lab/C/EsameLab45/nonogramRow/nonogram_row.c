#include<stdlib.h>
#include<stdint.h>


uint8_t* nonogram_row(const char* s, size_t* n) {
	if (s == NULL) return NULL;
	
	int conta = 0;
	int check = 0;
	int j = 0;
	uint8_t* res = malloc(j * sizeof(uint8_t));
	for (size_t i = 0; s[i] != 0; i++) {
		if (s[i] == '*') {
			check = 1;
			conta++;
		}
		else if (s[i] == ' ') {
			if (check == 1) {
				check = 0;
				j++;
				res = realloc(res, j * sizeof(uint8_t));
				res[j - 1] = conta;
				conta = 0;
			}
		}
	}
	if (conta != 0) {
		j++;
		res = realloc(res, j * sizeof(uint8_t));
		res[j - 1] = conta;
	}
	*n = j;
	return res;

}
