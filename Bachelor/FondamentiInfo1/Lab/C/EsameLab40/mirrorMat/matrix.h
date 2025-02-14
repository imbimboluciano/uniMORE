#pragma once
#include<stdlib.h>

struct matrix {
	size_t rows, cols;
	double* data;
};

extern struct matrix* mirror_mat(const struct matrix* m);
