#include<stdlib.h>
int* crea_inizializza(unsigned int n, int val) {
	int* res = calloc(n, sizeof(int));
	for (unsigned int i = 0; i < n; i++) {
		res[i] = val;
		val--;
	}
	return res;
}