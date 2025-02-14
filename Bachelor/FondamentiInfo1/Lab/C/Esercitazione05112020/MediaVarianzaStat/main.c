#include<stdlib.h>
#include<stdint.h>
#include "stat.h"



int main(void) {

	unsigned int n = 3;
	double* x = malloc(n * sizeof(double));
	x[0] = 4.0;
	x[1] = 6.0;
	x[2] = 9.0;
	double med = media(x, n);
	double var = varianza(x, n);

	free(x);
	return 0;
}