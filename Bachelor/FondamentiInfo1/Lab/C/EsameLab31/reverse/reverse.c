#include<stdlib.h>

void reverse(int* vec, size_t len, size_t from, size_t to) {
	if (vec != NULL || from > len || to > len ) {
		int* tmp;
		tmp = calloc(to - from, sizeof(int));
		for (size_t i = from, j = 0; i < to; i++) {
			 tmp[j] = vec[i];
			 j++;
		}
		 for (int i = to - 1, j = 0; i > (int)from - 1; i--) {
			 vec[i] = tmp[j];
			 j++;
		 }
		free(tmp);
	}

}