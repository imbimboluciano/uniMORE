#pragma once
#include<stdlib.h>

struct Matrix {
    size_t size;
    bool* data;
};


extern int MappaColori(const struct Matrix* m, const char* c, size_t c_size);