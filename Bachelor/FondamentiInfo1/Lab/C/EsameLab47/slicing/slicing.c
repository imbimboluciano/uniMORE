#include<stdlib.h>


int* slicing(const int* v, size_t* n, size_t start, size_t end, int step) {

	size_t nres = 0;

	int* res = calloc(end - start + 1, sizeof(int));
	if (step > 0) {
		for (size_t i = start; i <= end; i += step) {
			res[nres] = v[i];
			nres++;
		}
	}
	else {
		for (size_t i = end; i >= start; i += step) {
			res[nres] = v[i];
			nres++;
		}
	}
	

	*n = nres;
	return res;
}