#include "minheap.h"
#include<stdlib.h>


bool HeapMinPop(Heap* h, ElemType* e) {

	if (HeapIsEmpty(h))	return false;

	*e = *HeapGetNodeValue(h, 0);

	h->data[0] = h->data[h->size - 1];
	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));

	HeapMinMoveDown(h, 0);


	return true;

}