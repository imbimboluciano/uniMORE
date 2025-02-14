#pragma once
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<stdio.h>

struct Matrix {
    size_t size;
    bool* data;
};

extern int MappaColori(const struct Matrix* m, const char* c, size_t c_size);
