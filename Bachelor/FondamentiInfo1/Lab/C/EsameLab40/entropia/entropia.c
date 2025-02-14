#include<stdlib.h>
#include<math.h>

double entropia(const double* v, size_t n) {
	if (v == NULL || n == 0) return 0;
	double e = -1;
	double som = 0;
	for (size_t i = 0; i < n; i++) {
		som += (v[i] * log2(v[i]));
	}
	e *= som;
	return e;
}