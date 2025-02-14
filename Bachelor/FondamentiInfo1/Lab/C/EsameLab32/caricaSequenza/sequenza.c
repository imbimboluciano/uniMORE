#include "sequenza.h"

bool seq_load(const char* filename, struct seq* s) {
	if (filename == NULL || s == NULL) return false;
	FILE* f = fopen(filename, "rb");
	if (f == NULL) return false;
	uint16_t* val =  NULL;
	uint16_t temp;
	int i = 0;
	while (1) {
		fread(&temp, sizeof(uint16_t), 1, f);
		if (feof(f) != 0) break;
		i++;
		val = realloc(val, i * sizeof(uint16_t));
		val[i - 1] = temp;
	}
	s->len = i;
	s->values = calloc(i, sizeof(uint16_t));
	for (int j = 0; j < i; j++) {
		s->values[j] = val[j];
	}
	free(val);
	fclose(f);
	return true;
}