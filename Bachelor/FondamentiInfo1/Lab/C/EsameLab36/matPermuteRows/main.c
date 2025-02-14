#include "matrix.h"

int main(void) {
	double d[] = { 1,2,3,4,5,6,7,8,9 };
	struct matrix a = { 3,3,NULL };
	a.data = d;
	size_t p[] = { 2,1,0 };
	struct matrix* res = mat_permute_rows(&a,p);
	return 0;
}