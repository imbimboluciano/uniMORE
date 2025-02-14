#include<stdio.h>
#include<stdlib.h>

void stampa_cono(unsigned int h) {
	
	unsigned int col = h * 2 + 3;
	for (unsigned int i = 0; i < col; i++) {
		if (i == h + 1) {
			fprintf(stdout, "-");
		}
		else {
			fprintf(stdout, " ");
		}
	}
	fprintf(stdout, "\n");

	for (unsigned int r = 0,j = h,k = 2; r < h; r++,j--,k += 2) {
		for (unsigned int c = 0; c < col; c++) {
			if (r == h - 1) {
				if (c == 0 || c == col - 1) {
					fprintf(stdout, "_");
				}
				else if(c == j){
					fprintf(stdout, "/");
				}
				else if (c == j + k){
					fprintf(stdout, "\\");
				}
				else {
					fprintf(stdout, " ");
				}
			}
			else {
				if (c == j) {
					fprintf(stdout, "/");
				}
				else if (c == j + k) {
					fprintf(stdout, "\\");
				}
				else {
					fprintf(stdout, " ");
				}
			}
		}
		fprintf(stdout, "\n");
	}

}