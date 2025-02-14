#include <stdlib.h>

extern void potenza(double* d, size_t i);

int main(void) {
	double a[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
	size_t i, n = 10;

	for (i = 0; i < n; ++i) {
		potenza(&a[i], i);

	}
	return 0;
}