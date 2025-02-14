#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

extern void write_bin(const double* values, size_t n, FILE* f);

int main(void) {
	FILE* f = fopen("out.txt", "wb");
	if (f == NULL) return 0;
	double v[] = { 2,3,4 };
	write_bin(v, 3, f);
	return 0;
}