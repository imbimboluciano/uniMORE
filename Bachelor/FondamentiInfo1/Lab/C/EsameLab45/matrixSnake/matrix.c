#include "matrix.h"

double* matrix_snake(const struct matrix* m) {
	if (m == NULL)	return NULL;

	double* res = calloc(m->rows * m->cols, sizeof(double));
	size_t j = 0;
	size_t count = 0;
	for (size_t r = 0; r < m->rows; r++) {
		if (r % 2 == 0) {
			for (size_t c = 0; c < m->cols; c++) {
				res[count] = m->data[r * m->cols + c];
				count++;
			}
		}
		else {
			for (size_t c = m->cols ; c > 0; c--) {
				res[count] = m->data[r * m->cols + (c - 1)];
				count++;
			}
		}
		
	}
	
	return res;


}