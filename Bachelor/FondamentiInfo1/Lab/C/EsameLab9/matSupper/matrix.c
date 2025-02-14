#include "matrix.h"

int mat_isupper(const struct matrix* matr) {
	if (matr->M != matr->N) return 0;
	int quad = 1;
	for (size_t r = 0; r < matr->N; r++) {
		for (size_t c = 0; c < matr->M; c++) {
			if (c > r) {
				if (matr->data[r * matr->M + c] != 0) {
					quad = 0;
					break;
				}
			}
		}
	}
	if (quad == 1) return 1;
	else return 0;
}