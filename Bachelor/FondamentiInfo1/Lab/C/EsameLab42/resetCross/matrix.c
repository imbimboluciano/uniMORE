#include "matrix.h"

struct matrix* mat_reset_cross(const struct matrix* m, size_t ir, size_t ic) {
	if (m == NULL || ir > m->rows - 1 || ic > m->cols - 1)	return NULL;

	struct matrix* res = malloc(sizeof(struct matrix));
	res->cols = m->cols;
	res->rows = m->rows;
	res->data = calloc(res->rows * res->cols, sizeof(double));
	for (size_t r = 0; r < res->rows; r++) {
		for (size_t c = 0; c < res->cols; c++) {
			if (r == ir && c == ic) {
				res->data[r * res->cols + c] = m->data[r * m->cols + c];
			}
			else if (r == ir) {
				res->data[r * res->cols + c] = 0;
			}
			else if (c == ic) {
				res->data[r * res->cols + c] = 0;
			}
			else {
				res->data[r * res->cols + c] = m->data[r * m->cols + c];
			}
		}
	}

	return res;
}