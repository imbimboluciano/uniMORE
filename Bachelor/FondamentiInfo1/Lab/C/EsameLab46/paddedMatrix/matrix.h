#pragma once
#include<stdlib.h>

struct matrix {
    size_t rows, cols;
    double* data;
};

extern struct matrix* mat_pad(const struct matrix* mat);