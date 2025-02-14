#include "list.h"
#include <stdlib.h>

void BucketFill(Item* l, Item** v, int min, int max, int size) {

	for (Item* tmp = l; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		Item* sup = ListCreateEmpty();
		sup = ListInsertHead(&tmp->value, sup);
		v[(size - 1) * (*ListGetHeadValue(tmp) - min) / (max - min)] = ConcatList(v[(size - 1) * (*ListGetHeadValue(tmp) - min) / (max - min)], sup);
	}
	ListDelete(l);
}


Item* BucketSort(Item* l) {
	if (ListIsEmpty(l))
		return NULL;
	int min, max, size;
	GetMinMaxSize(l, &min, &max, &size);
	if (size == 1)
		return l;
	Item** v = calloc(size, sizeof(Item));

	BucketFill(l, v, min, max, size);
	l = NULL;
	for (int i = 0; i < size; i++) {
		l = ConcatList(l, BucketSort(v[i]));
	}

	free(v);
	return l;
}