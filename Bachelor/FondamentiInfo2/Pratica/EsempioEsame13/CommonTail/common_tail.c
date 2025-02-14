#include "list.h"

const Item* CommonTail(const Item* i1, const Item* i2) {

	if (ListIsEmpty(i1) || ListIsEmpty(i2))	return NULL;

	for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		for (const Item* box = i2; !ListIsEmpty(box); box = ListGetTail(box)) {
			if (ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(box)) == 0 && (ListGetHeadValue(tmp) == ListGetHeadValue(box))) {
				return tmp;
			}

		}
	}

	return NULL;


}
