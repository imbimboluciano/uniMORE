#include "matrix.h"

struct matrix* mat_submatrix(const struct matrix* mat, const int* row_idxs, const int* col_idxs) {
	if (mat == NULL || row_idxs == NULL || col_idxs == NULL)	return NULL;
	
	int trovato = 1;
	size_t i = 0;
	for ( i = 0; row_idxs[i] >= 0; i++) {
		if (row_idxs[i] > (int)mat->rows - 1) {
			trovato = 0;
		}
	}
	if (trovato == 0)	return NULL;
	trovato = 1;
	size_t j = 0;
	for ( j = 0; col_idxs[j] >= 0; j++) {
		if (col_idxs[j] > (int) mat->cols - 1) {
			trovato = 0;
		}
	}
	if (trovato == 0)	return NULL;

	int trovatoc = 0;
	trovato = 0;
	struct matrix* res = malloc(sizeof(struct matrix));
	res->cols = mat->cols - (mat->cols - j);
	res->rows = mat->rows - (mat->rows - i);
	res->data = calloc(res->rows * res->cols,sizeof(double));
	size_t count = 0;

	for (size_t r = 0; r < mat->rows; r++) {
		for (size_t h = 0; h < i; h++) {
			if ((int)r == row_idxs[h]) {
				trovato = 1;
				break;
			}
		}
		if (trovato == 0)	continue;
		for (size_t c = 0; c < mat->cols; c++) {
			trovatoc = 0;
			for (size_t h = 0; h < j; h++) {
				if ((int)c == col_idxs[h]) {
					trovatoc = 1;
					break;
				}
			}

			if (trovatoc == 1) {
				res->data[count] = mat->data[r * mat->cols + c];
				count++;
			}
			else {
				continue;
			}
		}
		trovato = 0;
	}

	return res;

}