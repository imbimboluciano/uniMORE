#include<stdlib.h>

char* converti(unsigned int n) {

	size_t dim = 0;  // contatore per contacifre
	unsigned int nn = n;
	while (nn != 0) {  // ciclo per contare le cifre
		nn /= 10;
		dim++;
	}
	int box = 0;
	char* ris = calloc(dim+1, 1);
	for (size_t i = 0; i < dim; i++) {
		box = n % 10;
		n /= 10;
		ris[dim - 1 - i] = (char)box + '0';

	}
	return ris;
}