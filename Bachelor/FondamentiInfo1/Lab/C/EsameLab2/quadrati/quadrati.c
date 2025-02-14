#include "quadrati.h"

void stampa_quadrato(unsigned int lato) {
	for (unsigned int i = 0; i < lato; i++) {
		for (unsigned int j = 0; j < lato; j++) {

			if (i != 0 && i != lato - 1) {
				if (j == 0) {
					
					fprintf(stdout, "%c", '*');
				}
				else if (j == lato - 1) {
					fprintf(stdout, "%c%c", '*', '\n');
				}
				else {
					fprintf(stdout, "%c", ' ');
				}
			}
			else {
				if (j == lato - 1) {
					fprintf(stdout, "%c%c", '*', '\n');
				}
				else
				{
					fprintf(stdout, "%c", '*');
				}
			}

		}
	}
	
}