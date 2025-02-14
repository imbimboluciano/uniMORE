#include "list.h"

Item* CreaDaMinori(const Item* i, int v) {

	Item* res = ListCreateEmpty();
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), &v) <= 0) {
			res = ListInsertBack(res, ListGetHeadValue(tmp));
		}
	}

	return res;
}
