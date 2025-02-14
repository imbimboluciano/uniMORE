#include "righe.h"

unsigned int conta_righe(FILE* f) {
	if (f == NULL) return 1;
	int r = 1;
	int c = 0;
	while (1){
		c = fgetc(f);
		if (c == EOF) break;
		if (c == '\n') r++;
	}

	return r;
}