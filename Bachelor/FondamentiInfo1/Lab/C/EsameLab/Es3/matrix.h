#pragma once
#include<stdlib.h>

struct matrix {
	size_t rows, cols;
	double* data;
};


extern struct matrix* mat_submatrix(const struct matrix* mat,const int* row_idxs, const int* col_idxs);