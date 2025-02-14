#pragma once
#include<stdlib.h>


struct matrix {
	size_t rows, cols;
	double* data;
};

extern struct matrix* mat_scale(const struct matrix* m, double x);
