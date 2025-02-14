#include "matrix.h"

int main(void) {
	struct matrix a = { 3,4,NULL };
	double d[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	a.data = d;
	struct vector* v = mat_vectorize(&a, BY_COLUMN);
	free(v);
	return 0;
}