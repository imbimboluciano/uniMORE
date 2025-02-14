#include "array.h"

double* array_remove(const double* arr, size_t n, size_t pos) {
	if (pos > n || arr == NULL) return NULL;
	size_t rpos = pos - 1;
	double* res = NULL;
	int trovato = 0;
	for (size_t i = 0; i < n; i++) {
		if (trovato == 1) {
			res[i - 1] = arr[i];
		}
		else {
			if (i == rpos) {
				trovato = 1;
			}
			else {
				res[i] = arr[i];
			}
			
		}
	}
	return res;
}
