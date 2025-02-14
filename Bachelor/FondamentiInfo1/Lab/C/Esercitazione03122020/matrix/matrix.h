#pragma once 
#include<stdint.h>
#include<stdlib.h>

struct matrix {
	size_t rows, cols;
	double* data;
};
extern struct matrix* mat_transpose(const struct matrix* mat);