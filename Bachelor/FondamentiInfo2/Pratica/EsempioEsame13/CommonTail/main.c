#include "list.h"

extern const Item* CommonTail(const Item* i1, const Item* i2);

int main(void) {
	ElemType v[] = { 4,5,6 };
	ElemType v2[] = { 2,3,6 };
	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();
	i1 = ListInsertBack(i1, v + 0);
	i1 = ListInsertBack(i1, v + 1);
	i1 = ListInsertBack(i1, v + 2);
	i2 = ListInsertBack(i2, v2 + 0);
	i2 = ListInsertBack(i2, v2 + 1);
	i2 = ListInsertBack(i2, v2 + 2);

	const Item* res = CommonTail(i1, i2);

	return 0;
}