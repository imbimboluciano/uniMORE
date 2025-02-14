#include "sparse_matrix.h"

int main(void) {
	double d[] = { 7.0, 9.0, 5.0 };
	uint32_t row[] = { 1, 2, 3 };
	uint32_t cols[] = { 1, 3, 2 };
	struct sparse_matrix a = { 4,4,3,NULL,NULL,NULL };
	a.data = d;
	a.rowidxs = row;
	a.colidxs = cols;
	double res = sm_get(&a, 1, 1);
	return 0;
}

