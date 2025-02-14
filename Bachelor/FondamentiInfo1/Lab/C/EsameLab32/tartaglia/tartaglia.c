#include<stdlib.h>

unsigned int* tartaglia(unsigned int* v, size_t n) {
	if (n == 0) {
		unsigned int* res = calloc(1, sizeof(char));
		*res = 1;
		return res;
	}
	if (n == 1) {
		unsigned int *res = calloc(2,sizeof(char));
		*res = 1;
		*(res + 1) = 1;
		return res;
	}
	unsigned int* res = NULL;
	int i = 0;
	i++;
	res = calloc((n + 2),sizeof(char));
	res[i - 1] = 1;
	for (size_t j = 0; j < n ; j++) {
		i++;
		res[i - 1] = v[j] + v[j + 1];
	}
	res[i] = 1;
	return res;
}