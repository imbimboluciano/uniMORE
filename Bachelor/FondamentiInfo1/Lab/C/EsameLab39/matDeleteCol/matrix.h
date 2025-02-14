#pragma once
#include<stdlib.h>

struct matrix {
	size_t rows, cols;
	double* data;
};


extern struct matrix* mat_delete_col(const struct matrix* m, size_t i);

