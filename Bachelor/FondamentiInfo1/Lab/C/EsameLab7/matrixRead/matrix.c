#include "matrix.h"

int matrix_read(struct matrix* matr, FILE* f) {
	if (matr == NULL)	return 0;
	fscanf(f, "%lu\n", &matr->N);
	fscanf(f, "%lu\n", &matr->M);
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
	matr->data = tmp;
	return 1;
}