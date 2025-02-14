#include "vector.h"

Vector* VectorRead(const char* filename) {
	if (filename == NULL) return NULL;
	FILE* f = fopen(filename, "r");
	if (f == NULL)	return NULL;

	Vector* res = calloc(1, sizeof(Vector));
	res->capacity = 1;
	res->size = 0;
	res->data = malloc(sizeof(ElemType));

	int c = 0;
	ElemType tmp;
	while ((c = ElemRead(f, &tmp) > 0)) {
		res->capacity *= 2;
		res->data = realloc(res->data, sizeof(ElemType) * res->capacity);
		res->data[res->size] = tmp;
		(res->size)++;
	}

	fclose(f);
	return res;
}


void VectorReadInsertSort(Vector *v,size_t lastpos) {
	int i;
	ElemType x = v->data[lastpos];
	for ( i = lastpos - 1; i >= 0 && x < v->data[i]; i--) {
		v->data[i + 1] = v->data[i];
	}
	v->data[i + 1] = x;
}

Vector* VectorReadSorted(const char* filename) {
	if (filename == NULL) return NULL;
	FILE* f = fopen(filename, "r");
	if (f == NULL)	return NULL;

	Vector* res = calloc(1, sizeof(Vector));
	res->capacity = 1;
	res->size = 0;
	res->data = malloc(sizeof(ElemType));
	int c = 0;
	ElemType tmp;
	while ((c = ElemRead(f, &tmp) > 0)) {
		res->capacity *= 2;
		res->data = realloc(res->data, sizeof(ElemType) * res->capacity);
		res->data[res->size] = tmp;
		VectorReadInsertSort(res, res->size);
		(res->size)++;
	}

	fclose(f);
	return res;
}