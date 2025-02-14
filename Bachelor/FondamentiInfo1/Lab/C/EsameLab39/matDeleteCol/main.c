#include "matrix.h"

int main(void) {

	struct matrix a = { 3,5,NULL };
	double d[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,12,15 };
	a.data = d;
	struct matrix* res = mat_delete_col(&a, 2);
	return 0;
}