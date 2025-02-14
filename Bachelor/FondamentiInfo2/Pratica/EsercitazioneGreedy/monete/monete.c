#include<string.h>
#include<stdlib.h>


int* Monete(int* tagli, size_t tagli_size, int budget) {
	if (budget <= 0) {
		return NULL;
	}
	int* res = calloc(tagli_size, sizeof(int));

	for (size_t i = 0; i < tagli_size; i++) {
		res[i] = budget / tagli[i];
		budget = budget % tagli[i];
	}

	return res;
}