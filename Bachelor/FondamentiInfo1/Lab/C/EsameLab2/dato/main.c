#include "dati.h"

int main(void) {
	unsigned int p = 0;
	struct dato* d = read_dati("dati1.txt", &p);
	free(d);
	return 0;
}