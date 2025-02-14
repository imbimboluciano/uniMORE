#include "matrix.h"

struct matrix* mat_pad(const struct matrix* mat) {
	if (mat == NULL) return NULL;

	struct matrix* res = malloc(sizeof(struct matrix));
	res->rows = mat->rows * 2 - 1;
	res->cols = mat->cols * 2 - 1;
	res->data = calloc(res->rows * res->cols, sizeof(double));
	size_t j = 0;
	for (size_t r = 0; r < res->rows; r++) {
		for (size_t c = 0; c < res->cols; c++) {
			if (r % 2 != 0) {
				res->data[r * res->cols + c] = 0;
			}
			else {
				if (c % 2 == 0) {
					res->data[r * res->cols + c] = mat->data[(r/2) * mat->cols + j];
					j++;
				}
				else {
					res->data[r * res->cols + c] = 0;
				}
			}
		}
		j = 0;
	}

	return res;


}