#include "minheap.h"

extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);

int main(void) {

	ElemType v[] = {4,6,1,2,12,23};
	Heap* res = HeapMinHeapify(v, 6);
	return 0;
}