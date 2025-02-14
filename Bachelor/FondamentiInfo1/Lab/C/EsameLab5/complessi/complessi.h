#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct complesso {
	double re, im;
};

extern int read_complesso(struct complesso* comp, FILE* f);
extern void write_complesso(const struct complesso* comp, FILE* f);
extern void prodotto_complesso(struct complesso* comp1, const struct complesso* comp2);
