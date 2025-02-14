#include<stdlib.h>
#include<stdint.h>

extern double media(double* x, unsigned int n);

double varianza(double* x, unsigned int n) {
	double somParziale = 0, m = media(x, n);
	for (int i = 0; i < n; ++i) {
		somParziale += ((*(x + i) - m) * (*(x + i) - m));
	}
	return somParziale / n;

}

