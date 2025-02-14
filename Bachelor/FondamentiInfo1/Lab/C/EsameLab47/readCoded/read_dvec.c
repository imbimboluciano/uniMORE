#include "read_dvec.h"

struct dvec* read_dvec_comp(const char* filename) {
	if (filename == NULL)	return NULL;

	struct dvec* res = malloc(sizeof(struct dvec));
	res->d = NULL;
	size_t i = 0;
	res->n = 0;
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		return res;
	}

	int16_t tmp;
	fread(&tmp, sizeof(int16_t), 1, f);
	if (feof(f) != 0 || ferror(f) != 0) {
		fclose(f);
		return res;
	}
	i++;
	res->d = realloc(res->d, i * sizeof(double));
	res->d[i - 1] = (tmp / pow(2,14));
	while (1) {
		fread(&tmp,sizeof(int16_t), 1, f);
		if (feof(f) != 0) break;
		i++;
		res->d = realloc(res->d,i * sizeof(double));
		res->d[i - 1] = (tmp / pow(2, 14));
	}

	res->n = i;
	fclose(f);
	return res;


}