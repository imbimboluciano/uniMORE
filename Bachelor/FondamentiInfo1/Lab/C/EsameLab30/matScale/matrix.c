#include "matrix.h"

struct matrix* mat_scale(const struct matrix* m, double x) {
	struct matrix* res = calloc(1, sizeof(struct matrix));
	res->rows = m->rows;
	res->cols = m->cols;
	res->data = calloc(res->rows * res->cols, sizeof(double));
	for (size_t r = 0; r < m->rows; r++) {
		for (size_t c = 0; c < m->cols; c++) {
			res->data[r * res->cols + c] = x * m->data[r * m->cols + c];
		}
	}
	return res;
}
