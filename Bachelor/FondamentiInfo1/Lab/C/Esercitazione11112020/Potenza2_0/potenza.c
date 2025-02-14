#include <stdlib.h>

void potenza(double* d, size_t i) {
	double pot = 1;
	for (size_t j = 0; j < i; ++j) {
		pot *= (*d);
	}
	*d = pot;
}