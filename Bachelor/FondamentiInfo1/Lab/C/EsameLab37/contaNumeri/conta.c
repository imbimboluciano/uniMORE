#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

unsigned int contanumeri(const char* nomefile) {
	FILE* f = fopen(nomefile, "r");
	if (f == NULL) return 0;
	int conta = 0;
	int c = 0;
	while (1) {
		c = fgetc(f);
		if (c == EOF) break;
		if (c >= 48 && c <= 57) conta++;
	}

	return conta;
}