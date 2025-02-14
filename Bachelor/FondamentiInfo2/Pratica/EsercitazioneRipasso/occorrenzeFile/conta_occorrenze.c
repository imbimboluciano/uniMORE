#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ContaOccorrenze(const char* filename, const char* str) {
	if (filename == NULL || str == NULL) return 0;
	FILE* f = fopen(filename, "r");
	if (f == NULL) return 0;
	char box[99];
	int occ = 0;
	while (1) {
		int ris = fscanf(f, "%s", box);
		if (ris == -1) break;
		if (!strcmp(box, str)) occ++;
	}
	fclose(f);
	return occ;
}