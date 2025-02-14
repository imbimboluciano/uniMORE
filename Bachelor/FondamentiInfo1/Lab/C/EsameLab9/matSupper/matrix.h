#pragma once
#include<stdlib.h>

struct matrix {
	size_t N, M;
	double* data;
};

extern int mat_isupper(const struct matrix* matr);