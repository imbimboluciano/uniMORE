#include "matrix.h"

struct matrix* mat_permute_rows(const struct matrix* m, const size_t* p) {
	if (m == NULL || p == NULL) return NULL;
	struct matrix* res = malloc(sizeof(struct matrix));
	res->rows = m->rows;
	res->cols = m->cols;
	res->data = calloc(res->rows * res->cols, sizeof(double));

	for (size_t i = 0; i < m->rows; i++) {
			size_t r = p[i];
			for (size_t c = 0; c < m->cols; c++) {
				res->data[i * res->cols + c] = m->data[r * m->cols + c];
			}
	}
	return res;
}