#include "matrix.h"

struct matrix* scambia_diagonali(const struct matrix* m) {
	if (m != NULL && m->rows == m->cols) {
		struct matrix* out = malloc(sizeof( struct matrix));
		out->rows = m->rows;
		out->cols = m->cols;
		out->data = malloc(out->rows * out->cols * sizeof(double));
		
		for (size_t r = 0; r < out->rows; r++) {
			for (size_t c = 0; c < out->cols; c++) {
				if (r == c || c == out->cols - 1 - r) {
					out->data[r * out->cols + c] = m->data[r*m->cols + out->cols - 1 - c];
				}
				else {
					out->data[r * out->cols + c] = m->data[r * m->cols + c];
				}
			}
		}
		return out;
	}
	return NULL;
}