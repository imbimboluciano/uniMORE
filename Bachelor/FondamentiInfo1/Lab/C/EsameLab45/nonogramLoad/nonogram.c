#include "nonogram.h"

bool nonogram_load(struct nonogram* ng, const char* filename) {
	if (filename == NULL || ng == NULL)	return false;
	FILE* f = fopen(filename, "r");
	if (f == NULL) return false;
	size_t n = 0;
	fscanf(f, "%zu", &n);
	fgetc(f);
	ng->n = n;
	ng->schema = calloc(n*n, sizeof(char));
	
	for (size_t r = 0; r < n; r++) {
		for (size_t c = 0; c < n; c++) {
			int k = fgetc(f);
			ng->schema[r * n + c] = k;
		}
		fgetc(f);
	}


	fclose(f);
	return true;
}