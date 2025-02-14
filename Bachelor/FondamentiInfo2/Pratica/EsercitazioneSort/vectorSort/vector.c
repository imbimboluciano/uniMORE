#include "vector.h"

void VectorSort(Vector* v) {
	if (v != NULL) {
		size_t i,dim = v->size;
		int ordinato = 0;
		while (dim > 1 && !ordinato) {
			ordinato = 1;
			for (i = 0; i < dim - 1; i++) {
				if (ElemCompare(v->data + i, v->data + i + 1) == 1) {
					ElemSwap(v->data + i, v->data + i + 1);
					ordinato = 0;
				}
			}
			dim--;
		}
	}
}