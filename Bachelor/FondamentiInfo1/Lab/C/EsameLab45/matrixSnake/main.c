#include "matrix.h"

int main(void) {

	struct matrix a = { 4,5,NULL };
	double d[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	a.data = d;
	double* res = matrix_snake(&a);
	free(res);
	return 0;
}