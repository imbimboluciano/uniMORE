#define _CRT_SECURE_NO_WARNINGS
#include<stdint.h>
#include<stdio.h>

void stampa_a(uint8_t n) {

	if (n % 2 != 0 && n >= 3) {
		for (size_t r = 0,k = n - 1,h = 1; r < n; r++,k--,h += 2) {
			for (size_t c = 0; c < n * 2; c++) {
				if (r == (n / 2) ) {
					if (c == k) {
						fprintf(stdout, "/");
					}
					else if (c == k + h) {
						fprintf(stdout, "\\");
					}
					else if(c < k + h && c > k){
						fprintf(stdout, "-");
					}
					else {
						fprintf(stdout, " ");
					}
				}
				else {
					if (c == k) {
						fprintf(stdout, "/");
					}
					else if (c == k + h) {
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
}