#include "matrix.h"

struct matrix* mat_rendiquadrata(const struct matrix* a) {
	if (a == NULL || a->rows == 0 || a->cols == 0) return NULL;
	struct matrix* res = malloc(sizeof(struct matrix));
	if (a->cols > a->rows) {
		res->cols = a->cols;
		res->rows = a->cols;
		res->data = calloc(res->cols * res->rows, sizeof(double));
		for (size_t r = 0; r < res->cols; r++) {
			for (size_t c = 0; c < res->rows; c++) {
				if (r >= a->rows) {
					res->data[r * res->cols + c] = 0;
				}
				else {
					res->data[r * res->cols + c] = a->data[r * a->cols + c];
				}
			}
		}
	}
	else {
		res->cols = a->rows;
		res->rows = a->rows;
		res->data = calloc(res->cols * res->rows, sizeof(double));
		for (size_t r = 0; r < res->cols; r++) {
			for (size_t c = 0; c < res->rows; c++) {
				if (c >= a->cols) {
					res->data[r * res->cols + c] = 0;
				}
				else {
					res->data[r * res->cols + c] = a->data[r * a->cols + c];
				}
			}
		}
	}


	return res;
	
}
