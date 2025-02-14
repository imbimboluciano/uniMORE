#include "matrici.h"

double* diag(double* matr, size_t n) {

	double* res = calloc(n, sizeof(double));
	size_t count = 0;
	for (size_t r = 0; r < n; r++) {
		for (size_t c = 0; c < n; c++) {
			if (r == c) {
				res[count] = matr[r * n + c];
				count++;
			}
		}
	}

	return res;
}
