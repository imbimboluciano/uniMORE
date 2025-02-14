#include "matrix.h"

struct matrix* mat_delete_col(const struct matrix* m, size_t i) {
	if (m == NULL || i > m->cols - 1) return NULL;
	if (m->cols == 1) return NULL;
	struct matrix* res = malloc(sizeof(struct matrix));
	res->rows = m->rows;
	res->cols = m->cols - 1;
	res->data = calloc(res->rows * res->cols, sizeof(double));
	int trovato = 0;

	for (size_t r = 0; r < m->rows; r++) {
		for (size_t c = 0; c < m->cols; c++) {
			if (c == i) {
				trovato = 1;
				continue;
			}
			if (trovato == 1) {
				res->data[r * res->cols + c - 1] = m->data[r * m->cols + c];
			}
			else {
				res->data[r * res->cols + c] = m->data[r * m->cols + c];
			}
		}
		trovato = 0;
	}

	return res;
}
