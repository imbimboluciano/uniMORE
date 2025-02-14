#include "matrix.h"

int main(void) {
	FILE* f = fopen("A.txt", "r");
	if (f == NULL)	return 0;
	struct matrix a = { 0,0,NULL };
	int res = matrix_read(&a, f);
	return 0;
}