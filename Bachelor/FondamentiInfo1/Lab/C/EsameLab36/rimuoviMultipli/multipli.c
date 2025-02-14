#include<stdlib.h>

int* rimuovi_multipli(const int* v, size_t size, size_t* newsize) {
	int* res = NULL;
	size_t n = 0;
	int multiplo = 0;
	for (size_t i = 0; i < size; i++) {
		multiplo = 0;
		for (size_t j = 0; j < size; j++) {
			if (i != j) {
				if (v[i] % v[j] == 0) {
					multiplo = 1;
					break;
				}
			}
		}
		if (multiplo == 0) {
			n++;
			res = realloc(res, n * sizeof(int));
			res[n - 1] = v[i];
		}
	}
	*newsize = n ;
	return res;
}