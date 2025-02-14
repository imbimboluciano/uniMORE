#include "array.h"

void array_remove(double* arr, size_t* pn, size_t pos) {
	size_t rpos = pos - 1;
	int trovato = 0;
	for (size_t i = 0; i < *pn; i++) {
		if (trovato == 1) {
			arr[i - 1] = arr[i];
		}
		else
		{
			if (i == rpos) trovato = 1;
		}
		
	}
	if (trovato == 1) *pn = *pn - 1;
}