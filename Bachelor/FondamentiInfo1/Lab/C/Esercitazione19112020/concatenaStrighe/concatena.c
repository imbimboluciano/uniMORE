#include<stdlib.h>
#include<string.h>

char* concatena(const char* prima, const char* seconda) {

	size_t dim = 0;
	size_t lPrima = 0;
	size_t lSeconda = 0;
	if (prima != NULL) {
		lPrima = strlen(prima);
		dim += lPrima;
	}
	if (seconda != NULL) {
		lSeconda = strlen(seconda);
		dim += lSeconda;
	}
	char *s = calloc(dim + 1,1);
	for (size_t i = 0; i < dim; i++) {
		if (i < lPrima) {
			s[i] = prima[i];
		}
		else {
			s[i] = seconda[i - lPrima];
		}
	}

	return s;
}

