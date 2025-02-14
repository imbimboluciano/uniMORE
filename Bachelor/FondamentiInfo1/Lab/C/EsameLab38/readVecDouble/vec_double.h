#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

struct vec_double {
	uint32_t size;
	double* data;
};

extern struct vec_double* read_vec_double(const char* filename);