#include "minheap.h"

extern void HeapDeleteNode(Heap* h, int k);

int main(void) {

	ElemType v[] = { 5,6,2,1,4 };
	Heap* h = HeapCreateEmpty();
	HeapMinInsertNode(h, v + 0);
	HeapMinInsertNode(h, v + 1);
	HeapMinInsertNode(h, v + 2);
	HeapMinInsertNode(h, v + 3);
	HeapMinInsertNode(h, v + 4);

	HeapDeleteNode(h, 3);
	return 0;
}