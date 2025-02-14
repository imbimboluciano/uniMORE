#include "matrix.h"

int main(void) {
	struct matrix a = {4,3,NULL};
	double d[] = { 1,2,3,5,6,7,9,10,11,13,14,15 };
	a.data = d;
	struct matrix* res = mirror_mat(&a);
	free(res->data);
	free(res);
	return 0;
}