#include "array.h"

int main(void) {
	double arr[] = { 5.7,6.8,9.2 };
	double* res = array_remove(arr, 3, 2);
	free(res);
	return 0;
}