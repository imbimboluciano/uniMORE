#include "list.h"

extern Item* CopiaDaN(const Item* i, int n);

int main(void) {

	ElemType v[] = { 5,9,12 };
	Item* list = ListCreateEmpty();
	list = ListInsertBack(list, v + 0);
	list = ListInsertBack(list, v + 1);
	list = ListInsertBack(list, v + 2);

	Item* res = CopiaDaN(list, 2);

	return 0;
}