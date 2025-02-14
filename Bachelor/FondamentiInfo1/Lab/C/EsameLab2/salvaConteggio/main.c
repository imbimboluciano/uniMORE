#include "dati.h"
int main(void) {
	struct dato x[] = { {0.1,0}, {1.45,2}, {0.81,0} };
	salva_conteggio_bin("file.bin", x, 3);
}