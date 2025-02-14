#include "matrix.h"

int main(void) {


	struct matrix a = { 3,4,NULL };
	double d[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	size_t row_idxs[] = { 1, 2, -1 };
	size_t col_idxs[] = { 0,2, 3, -1 };
	struct matrix* res = mat_submatrix(&a, row_idxs, col_idxs);
	return 0;
}