#include<stdlib.h>

int* clamped(const int* v, size_t n, int min, int max) {
	if (v == NULL || n == 0 || min > max) return NULL;
	int* res = calloc(n, sizeof(int));
	for (size_t i = 0; i < n; i++) {
		if (v[i] < min) {
			res[i] = min;
		}
		else if (v[i] >= min && v[i] <= max) {
			res[i] = v[i];
		}
		else {
			res[i] = max;
		}
	}
	return res;
}