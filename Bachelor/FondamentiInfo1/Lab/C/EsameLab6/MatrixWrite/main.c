#include "matrix.h"

int main(void) {
	FILE* f = fopen("out.txt", "w");
	if(f == NULL)	return 0;
	struct matrix a = { 2,3,NULL };
	double d[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	a.data = d;
	matrix_write(&a, f);
	fclose(f);
	return 0;
}