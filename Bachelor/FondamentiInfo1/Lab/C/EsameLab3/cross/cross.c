#include<stdio.h>

void stampa_cross(unsigned int n) {

	for (size_t r = 0; r <= n * 2; r++) {
		for (size_t c = 0; c <= n * 2; c++) {
			if (r == c) {
				if (r == n ) {
					fprintf(stdout, "x");
				}
				else {
					fprintf(stdout, "\\");
				}
			}
			else if(r + c == n * 2 ) {
				fprintf(stdout, "/");
			}
			else {
				fprintf(stdout, " ");
			}
		}
		fprintf(stdout, "\n");
	}
}