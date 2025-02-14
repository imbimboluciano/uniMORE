#include <stdlib.h>

extern void potenza(double* d, size_t i);

int main(void) {
	 double a[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
	 size_t i, n = 10;
	
		 for (i = 0; i < n; ++i) {
		 double d = a[i];
		 potenza(&d, i);
		 a[i] = d;
		
	}
	 return 0;
	 }