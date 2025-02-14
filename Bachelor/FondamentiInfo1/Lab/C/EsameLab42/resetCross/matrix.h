#pragma once
#include <stdlib.h>

struct matrix {
    size_t rows, cols;
    double* data;
};

extern struct matrix* mat_reset_cross(const struct matrix* m, size_t ir, size_t ic);