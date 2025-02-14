#include<stdlib.h>
#include<stdint.h>

double media(double* x, unsigned int n) {
	double s = 0;
	for (int i = 0; i < n; ++i) {
		s += +*(x + i);
	}
	return (s/n);
}