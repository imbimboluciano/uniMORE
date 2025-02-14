#include "matrix.h"

void matrix_write(const struct matrix* matr, FILE* f) {
	if (matr != NULL) {
		fprintf(f, "%ld\n", matr->N);
		fprintf(f, "%ld\n", matr->M);
		for (size_t r = 0; r < matr->N; r++) {
			for (size_t c = 0; c < matr->M; c++) {
				if (c == matr->M - 1) {
					fprintf(f, "%.6lf\n", matr->data[r * matr->M + c]);
				}
				else {
					fprintf(f, "%.6lf\t", matr->data[r * matr->M + c]);
				}
				
			}
		}
	}
}