#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct matrix {
	size_t rows, cols;
	double* data;
};

extern bool matrix_read(struct matrix* m, FILE* f);
