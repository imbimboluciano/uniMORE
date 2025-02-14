#include "matrix.h"

bool scalar_mult(struct matrix* dst, const struct matrix* src, double k, bool accumulate) {
	if (dst == NULL || src == NULL)	return false;
	if (dst->rows != src->rows || dst->cols != src->cols)	return false;

	for (size_t r = 0; r < dst->rows; r++) {
		for (size_t c = 0; c < dst->cols; c++) {
			if (accumulate == false) {
				dst->data[r * dst->cols + c] = k * src->data[r * src->cols + c];
			}
			else {
				dst->data[r * dst->cols + c] += k * src->data[r * src->cols + c];
			}
		}
	}

	return true;
}