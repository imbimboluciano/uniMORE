#include<stdlib.h>

extern int* convolution3(const int* v, size_t lenv, const int k[3]);

int main(void) {
	int v[] = { 1, 2, 3, 4, 3, 2, 1 };
	int k[3] = { 2, -1, 1 };
	int* c = convolution3(v, 7, k);
	return 0;
}