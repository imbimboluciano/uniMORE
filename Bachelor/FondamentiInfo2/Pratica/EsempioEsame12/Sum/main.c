#include "list.h"

extern Item* Sum(const Item* i1, const Item* i2);

int main(void) {
	ElemType v1[] = {1,2,3,4 };
	ElemType v2[] = { 3,8,1 };
	Item* l1 = ListCreateEmpty();
	Item* l2 = ListCreateEmpty();
	for (int i = 0; i < 4; i++) {
		l1 = ListInsertBack(l1, v1 + i);
	}
	for (int i = 0; i < 3; i++) {
		l2 = ListInsertBack(l2,v2 + i);
	}

	Item* l3 = Sum(l1, l2);

	return 0;
}