#include "minheap.h"

bool IsHeap(const Heap* h) {
	if (h->size == 0) {
		return false;
	}
	int size = (int)h->size;
	for (size_t i = 0; i < h->size; i++) {
		int r = HeapRight(i);
		int l = HeapLeft(i);
		if (l < size && r > size) { // solo figlio sinistro
			if (h->data[i] >= h->data[l])
				return false;
		}
		else if (l > size && r < size) { // solo figlio destro
			if (h->data[i] >= h->data[r])
				return false;
		}
		else if(l < size && r < size){
			if (h->data[i] >= h->data[l] || h->data[i] >= h->data[r])
				return false;
		}
	}
	return true;
}