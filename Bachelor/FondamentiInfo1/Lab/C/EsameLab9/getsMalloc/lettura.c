#include "lettura.h"

char* fgets_malloc(FILE* f) {
	if (f == NULL) return NULL;
	int c = fgetc(f);
	if (c == EOF) return NULL;
	if (c == '\n') {
		return '\0';
	}
	int i = 1;
	char* res = NULL;
	res = realloc(res, i * sizeof(char));
	res[i - 1] = c;
	while (1)
	{
		c = fgetc(f);
		if (c == '\n' || c == EOF) {
			i++;
			res = realloc(res, i * sizeof(char));
			res[i - 1] = '\0';
			break;
		} 
		i++;
		res = realloc(res, i * sizeof(char));
		res[i - 1] = c;

	}
	return res;
}