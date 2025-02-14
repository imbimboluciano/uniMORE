#include<stdlib.h>

int *rotate(const int* vec, size_t len, size_t r){
	if (vec == NULL) return NULL;
	int* res = calloc(len, sizeof(int));
	for (size_t j = 0; j < len; j++) {
		res[j] = vec[j];
	}
    for (size_t i = 0; i < r; i++) {
        int j, last;   
        last = res[len - 1];
        for (j = len - 1; j > 0; j--) {   
            res[j] = res[j - 1];
        }  
        res[0] = last;
    }
	return res;
}
