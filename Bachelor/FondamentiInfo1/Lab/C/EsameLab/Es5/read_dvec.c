#include "read_dvec.h"


struct dvec* read_dvec_comp(const char* filename) {
	if (filename == NULL)	return NULL;
	struct dvec* res = malloc(sizeof(struct dvec));
	res->d = NULL;
	res->n = 0;
	FILE* f = fopen(filename, "rb");
	if (f == NULL)	return res;
	int16_t t;
	size_t j = 0;
	fread(&t, sizeof(int16_t), 1, f);
	if (feof(f) != 0) {
		fclose(f);
		return res;
	}
	
	j++;
	res->d = realloc(res->d, j * sizeof(double));
	res->d[j - 1] = t / pow(2, 14);
	while (1)
	{
		fread(&t, sizeof(int16_t), 1, f);
		if (feof(f) != 0) break;
		j++;
		res->d = realloc(res->d, j * sizeof(double));
		res->d[j - 1] = t / pow(2, 14);
	}

	res->n = j;
	fclose(f);
	return res;
}