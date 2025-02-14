#include "vettori.h"

double prodotto_scalare(const double* x, const double* y, size_t n) {
	if (n == 0 || x == NULL || y == NULL) return 0;
	double ps = 0;
	for (size_t i = 0; i < n; i++) {
		ps += x[i] * y[i];
	}
	return ps;

}