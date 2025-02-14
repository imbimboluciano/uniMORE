#include<stdlib.h>
#include<stdint.h>
#include "stat.h"


double media(double* x, unsigned int n) {
	if (x != NULL) {
		double s = 0;
		for (unsigned int i = 0; i < n; ++i) {
			s += +*(x + i);
		}
		return (s / n);
	}
	return 0;
}

double varianza(double* x, unsigned int n) {
	if (x != NULL) {
		double somParziale = 0, m = media(x, n);
		for (unsigned int i = 0; i < n; ++i) {
			somParziale += ((*(x + i) - m) * (*(x + i) - m));
		}
		return somParziale / n;
	}
	return 0;
}

