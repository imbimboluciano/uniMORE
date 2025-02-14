#include "matrix.h"

int main(void) {
	struct matrix a = { 1,3,NULL };
	double d[] = {7,8,9};
	a.data = d;
	struct matrix* res = mat_scale(&a, 2);
	return 0;
}