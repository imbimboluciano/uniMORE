#include "sciatori.h"

Sciatore* Accoppia(double* altezze, double* lunghezze, size_t v_size) {
	if (v_size == 0) return NULL;


	Sciatore* res = malloc(v_size * sizeof(Sciatore));
	size_t trovatol = 0;
	double min = 1000;
	double valAss = 0;
	for (size_t i = 0; i < v_size; i++) {
		for (size_t j = 0; j < v_size; j++) {
			if (lunghezze[j] == -1) {
				continue;
			}
			valAss = fabs(altezze[i] - lunghezze[j]);
			if (valAss < min) {
				min = valAss;
				trovatol = j;
			}
		}

		for (size_t k = 0; k < v_size; k++) {
			if (k == trovatol) {
				res[i].a = altezze[i];
				res[i].l = lunghezze[k];
				lunghezze[k] = -1;
				break;
			}
		}
		min = 1000;
	}

	return res;
}