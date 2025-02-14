#include<stdlib.h>

int* prodotto(const int* v, size_t n) {
	if (v == NULL || n == 0 || n == 1) return NULL;
	int* res = calloc(n, sizeof(int));
	int prod;
	for (size_t i = 0; i < n; i++) {
		prod = 1;
		for (size_t j = 0; j < n; j++) {
			if (i != j) prod *= v[j];
		}
		res[i] = prod;
	}
	return res;
}