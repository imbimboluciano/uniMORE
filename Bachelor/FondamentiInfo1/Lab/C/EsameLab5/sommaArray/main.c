#include "array.h"

int main(void) {
	double arr1[] = { 5.8,6.7,5.4 };
	double arr2[] = { 4.7,3.4,8.1 };
	size_t n = 3;
	double* res = array_somma(arr1, arr2, n);
	free(res);
	return 0;
}