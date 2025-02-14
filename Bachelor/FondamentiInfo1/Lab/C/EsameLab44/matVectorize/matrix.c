#include "matrix.h"

struct vector* mat_vectorize(const struct matrix* m, enum vectorize_by dir) {
	if (m == NULL)	 return NULL;
	if (dir != BY_ROW && dir != BY_COLUMN)	return NULL;

	struct vector* res = malloc(sizeof(struct vector));
	res->n = m->rows * m->cols;
	res->data = calloc(m->rows * m->cols, sizeof(double));

	int count = 0;
	if (dir == BY_ROW) {
		for (size_t r = 0; r < m->rows; r++) {
			for (size_t c = 0; c < m->cols; c++) {
					res->data[r * m->cols + c] = m->data[r * m->cols + c];

			}
		}
	}
	else {
		for (size_t c = 0; c < m->cols; c++) {
			for (size_t r = 0; r < m->rows; r++) {
				res->data[count] = m->data[r * m->cols + c];
				count++;
			}
		}
	}

	return res;

}