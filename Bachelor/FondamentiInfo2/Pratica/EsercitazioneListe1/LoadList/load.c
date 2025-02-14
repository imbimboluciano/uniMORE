#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include<stdio.h>
#include<stdlib.h>


Item* ListLoad(const char* filename) {
	if (filename == NULL) return NULL;

	FILE* f = fopen(filename, "r");
	if (f == NULL) return NULL;
	Item* fileValue = NULL;
	ElemType tmp;
	int ris;
	while ((ris = fscanf(f, "%d", &tmp)) > 0) {
		fileValue = ListInsertHead(&tmp, fileValue);
	}

	/*Item* box = fileValue;
	while (box) {
		fprintf(stdout, "%d ", box->value);
		box = box->next;
	}*/


	fclose(f);
	return fileValue;
}