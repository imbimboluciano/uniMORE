#include "minheap.h"
#include<stdlib.h>
#include<string.h>

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {

	Heap* h = HeapCreateEmpty();
	h->size = v_size;
	h->data = calloc((v_size),sizeof(ElemType));
	for (size_t i = 0; i < h->size; i++) {
		h->data[i] = v[i];
	}

	for (int i = (int)h->size - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}

	return h;
}