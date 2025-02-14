#include "matrix.h"

struct matrix* mat_transpose(const struct matrix* mat) {
	if (mat != NULL) {
		struct matrix* out = malloc(sizeof(struct matrix));
		out->rows = mat->cols;
		out->cols = mat->rows;
		out->data = malloc((mat->cols * mat->rows) * sizeof(double));

		for (size_t r = 0; r < out->rows; r++) {
			for (size_t c = 0; c < out->cols; c++) {
				out->data[r * out->cols + c] = mat->data[c * mat->cols + r];
			}
		}
		return out;

	}
	return NULL;
}