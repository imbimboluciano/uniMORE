#include "array.h"

double* array_somma(const double* arr1, const double* arr2, size_t n) {
	double* res = calloc(n, sizeof(double));
	for (size_t i = 0; i < n; i++) {
		res[i] = arr1[i] + arr2[i];
	}
	return res;
}