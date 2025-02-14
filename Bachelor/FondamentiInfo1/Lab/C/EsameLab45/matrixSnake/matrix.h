#pragma once
#include<stdlib.h>


struct matrix {
    size_t rows, cols;
    double* data;
};


extern double* matrix_snake(const struct matrix* m);