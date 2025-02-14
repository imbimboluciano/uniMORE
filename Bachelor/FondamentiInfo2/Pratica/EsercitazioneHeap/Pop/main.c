#include "minheap.h"
#include<stdlib.h>

extern bool HeapMinPop(Heap* h, ElemType* e);

int main(void) {

	Heap* h = HeapCreateEmpty();
	ElemType v[] = { 32,2,1,4,5,6 };
	h->size = 6;
	h->data = calloc(6,sizeof(ElemType));
	for (size_t i = 0; i < h->size; i++) {
		h->data[i] = v[i];
	}

	ElemType e = 0;
	bool res = HeapMinPop(h, &e);
	return 0;
}