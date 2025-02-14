#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

extern void stampa_tavola_pitagorica(FILE* f, unsigned int n);

int main(void) {
	FILE* f = fopen("pitagora.txt", "w");
	if (f == NULL) return 0;
	stampa_tavola_pitagorica(f, 5);
	return 0;
}