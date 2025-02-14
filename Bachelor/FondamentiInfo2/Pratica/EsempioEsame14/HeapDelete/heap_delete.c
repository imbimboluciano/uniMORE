#include "minheap.h"
#include <stdlib.h>

void HeapDeleteNode(Heap* h, int k) {
	if (k < 0 || k >= (int)h->size) {
		return;
	}

	
	h->data[k] = 0;
	for (int i = k + 1; i < (int)h->size; i++) {
		h->data[i - 1] = h->data[i];
	}
	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	for (int i = k; i < (int)h->size; i++) {
		HeapMinMoveDown(h, i);
	}

}