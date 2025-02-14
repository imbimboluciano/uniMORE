#include "minheap.h"



int main(void) {
	ElemType v[] = { 1, 3 ,4, 6, 4 };
	Heap* h = HeapCreateEmpty();
	h->data = v;
	h->size = 5;

	return 0;
}