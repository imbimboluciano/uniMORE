#include "minheap.h"

extern bool IsHeap(const Heap* h);

int main(void) {
	ElemType v[] = { 1, 3 ,4, 6, 4 };
	Heap* h = HeapCreateEmpty();
	h->data = v;
	h->size = 5;

	bool res = IsHeap(h);
	return 0;
}