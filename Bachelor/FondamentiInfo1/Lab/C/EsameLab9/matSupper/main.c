#include "matrix.h"

int main(void) {
	struct matrix a = { 3,3,NULL };
	double d[] = { 1,0,0,4,5,0,7,8,9 };
	a.data = d;
	int res = mat_isupper(&a);
	return 0;
}