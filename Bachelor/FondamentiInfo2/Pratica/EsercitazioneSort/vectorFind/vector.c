#include "vector.h"

int VectorFind(const Vector* v, const ElemType* e) {
	if (v == NULL)	return -1;

	int res = -1;
	size_t fine = v->size;
	size_t inizio = 0;
	size_t med = ((inizio + fine)/ 2) - 1;
	for (size_t i = inizio; i < fine; i++) {
		if (ElemCompare(v->data + med, e) == 0) {
			res = med;
			fine = med;
			med = ((inizio + fine) / 2) - 1;
		}
		else if (ElemCompare(v->data + med, e) == -1) {
			inizio = med + 1;
			med = ((inizio + fine) / 2) - 1;
		}
		else {
			fine = med;
			med = ((inizio + fine) / 2) - 1;
		}
	}


	return res;
}