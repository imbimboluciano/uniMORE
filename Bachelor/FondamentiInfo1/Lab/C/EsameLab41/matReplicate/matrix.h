#pragma once
#include<stdlib.h>

struct matrix {
	size_t rows, cols;
	double* data;
};

extern struct matrix* mat_replicate(const struct matrix* m);