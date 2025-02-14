#include "minheap.h"
#include<string.h>

extern Heap* MergeHeap(const Heap* h1, const Heap* h2);

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	// Costruisco la heap con gli elementi del vettore v
	Heap* h = HeapCreateEmpty();
	h->size = v_size;
	h->data = malloc(sizeof(ElemType) * (v_size));
	memcpy(h->data, v, v_size * sizeof(ElemType));
	for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
		HeapMinMoveDown(h, i);
	}
	return h;
}

int main(void) {
	ElemType v1[] = { 6,7,8,9 };
	ElemType v2[] = { 10,11,12 };
	Heap* h1 = HeapCreateEmpty();
	Heap* h2 = HeapCreateEmpty();
	h1 = HeapMinHeapify(v1, 4);
	h2 = HeapMinHeapify(v2, 3);


	Heap* h3 = MergeHeap(h1, h2);
	return 0;
}
