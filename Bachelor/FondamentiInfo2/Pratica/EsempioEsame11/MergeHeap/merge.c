#include "minheap.h"


Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	Heap* h3 = HeapCreateEmpty();

	for (size_t i = 0; i < h1->size; i++) {
		HeapMinInsertNode(h3, &h1->data[i]);
	}
	for (size_t i = 0; i < h2->size; i++) {
		HeapMinInsertNode(h3, &h2->data[i]);
	}

	return h3;
}