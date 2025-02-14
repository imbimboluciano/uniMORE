#include "matrix.h"

bool matrix_read(struct matrix* m, FILE* f) {
	if (m == NULL)	return false;
	fscanf(f, "%lu\n", &m->rows);
	fscanf(f, "%lu\n", &m->cols);
	int ris;
	int i = 0;
	double temp;
	double* tmp = NULL;
	while (1) {
		ris = fscanf(f, "%lf\n", &temp);
		if (ris == -1) break;
		i++;
		tmp = realloc(tmp, i * sizeof(double));
		tmp[i - 1] = temp;
	}
	m->data = tmp;
	return true;
}