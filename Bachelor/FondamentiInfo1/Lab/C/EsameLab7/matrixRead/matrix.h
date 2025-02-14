#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct matrix {
	size_t N, M;
	double* data;
};

extern int matrix_read(struct matrix* matr, FILE* f);
