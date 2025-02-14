#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void stampa_tavola_pitagorica(FILE* f, unsigned int n) {
	for (unsigned int i = 1; i <= n; i++) {
		for (unsigned int j = 1; j <= n; j++) {
			if (j == n) {
				fprintf(stdout, "%u\n", i * j);
			}
			else
			{
				fprintf(stdout, "%u\t", i * j);
			}
			
		}
	}
}