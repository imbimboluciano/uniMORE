#include "matrix.h"

struct matrix* mat_delete_row(const struct matrix* m, size_t i) {
	if (m == NULL || i > m->rows - 1) return NULL;
	struct matrix* res = malloc(sizeof(struct matrix));
	res->rows = m->rows - 1;
	res->cols = m->cols;
	res->data = calloc(res->rows * res->cols,sizeof(double));
	int check = 0;
	for (size_t r = 0; r < m->rows; r++) {
		if (r == i) {
			check = 1;
			continue;
		}
		for (size_t c = 0; c < m->cols; c++) {
			if (check == 1) {
				res->data[(r - 1) * res->cols + c] = m->data[r * m->cols + c];
			}
			else {
				res->data[r * res->cols + c] = m->data[r * m->cols + c];
			}
			
		}
	}

	return res;

}