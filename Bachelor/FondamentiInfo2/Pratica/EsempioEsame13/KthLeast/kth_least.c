#include "minheap.h"
#include<stdlib.h>

void InsMinore(int* v, int lastpos) {
	int x = v[lastpos], i;
	for (i = lastpos - 1; i >= 0 && x < v[i]; i--) {
		v[i + 1] = v[i];
	}
	v[i + 1] = x;
}

void InsertionSort(int* v, size_t v_size) {
	int i;
	for (i = 1; i < (int)v_size; i++) {
		InsMinore(v, i);
	}
}

ElemType KthLeast(const Heap* h, int k) {

	ElemType* res = calloc(h->size, sizeof(ElemType));
	for (size_t i = 0; i < h->size; i++) {
		res[i] = h->data[i];
	}

	InsertionSort(res, h->size);

	ElemType r = res[k - 1];
	free(res);
	return r;
}