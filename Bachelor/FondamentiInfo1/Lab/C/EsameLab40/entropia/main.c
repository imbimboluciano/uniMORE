#include<stdlib.h>

extern double entropia(const double* v, size_t n);

int main(void) {
	double v[] = { 1,2,3,0 };
	double res = entropia(v, 4);
	return 0;
}