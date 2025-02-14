#include "vec_double.h"

struct vec_double* read_vec_double(const char* filename) {
	if (filename == NULL)	return NULL;
	FILE* f = fopen(filename, "rb");
	if (f == NULL)  return NULL;

	struct vec_double* res = malloc(sizeof(struct vec_double));
	uint32_t tmp;
	double temp;
	
	fread(&tmp, sizeof(uint32_t), 1, f);
	if (ferror(f) != 0 || feof(f) != 0) {
		fclose(f);
		free(res);
		return NULL;
	}
	res->size = tmp;
	res->data = calloc(tmp, sizeof(double));

	for (int i = 0; i < (int)tmp; i++) {
		fread(&temp, sizeof(double), 1, f);
		if (ferror(f) != 0 || feof(f)) {
			free(res->data);
			free(res);
			fclose(f);
			return NULL;
		}
		res->data[i] = temp;
	}
	fclose(f);
	return res;
}