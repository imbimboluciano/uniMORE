#include "list.h"

extern Item* BucketSort(Item* l);

int main(void) {
	ElemType v[] = { 3,7,4 };
	Item* h = ListCreateEmpty();
	h = ListInsertBack(h, v + 0);
	h = ListInsertBack(h, v + 1);
	h = ListInsertBack(h, v + 2);

	Item* res = BucketSort(h);
	return 0;
}