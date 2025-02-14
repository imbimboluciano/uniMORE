#include "matrix.h"

int main(void) {
	
	struct matrix a = { 2,3,NULL };
	double d[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	a.data = d;

	struct matrix* res = mat_pad(&a);
	free(res->data);
	free(res);

	return 0;
}