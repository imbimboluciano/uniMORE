#include "minheap.h"

extern void HeapMinMoveDownRec(Heap* h, int i);

int main(void) {
	Heap* d = HeapCreateEmpty();
	ElemType v[] = { 32,5,4,6,12,23 };
	d->size = 6;
	d->data = v;


	HeapMinMoveDownRec(d, 0);
	return 0;
}