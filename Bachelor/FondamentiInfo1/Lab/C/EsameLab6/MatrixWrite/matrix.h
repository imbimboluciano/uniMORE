#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

struct matrix {
	size_t N, M;
	double* data;
};

extern void matrix_write(const struct matrix* matr, FILE* f);
