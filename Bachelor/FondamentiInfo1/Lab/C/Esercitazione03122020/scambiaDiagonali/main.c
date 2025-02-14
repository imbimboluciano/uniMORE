#include "matrix.h"

int main(void) {
	double d[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
	struct matrix a = {3,3,NULL};
	a.data = d;
	struct matrix* res = scambia_diagonali(&a);

	free(res->data);
	free(res);
	return 0;
}