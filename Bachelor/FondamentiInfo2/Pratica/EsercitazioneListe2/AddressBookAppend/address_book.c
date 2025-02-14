#include "list.h"

Item* Append(const Item* i1, const Item* i2) {

	if (ListIsEmpty(i1) && ListIsEmpty(i2))	return NULL;

	Item* res = NULL;
	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		res = ListInsertBack(res, &tmp1->value);
	}
	for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
		res = ListInsertBack(res, &tmp2->value);
	}

	return res;
}