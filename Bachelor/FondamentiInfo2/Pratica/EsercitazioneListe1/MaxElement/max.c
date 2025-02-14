#include "list.h"

const ElemType* MaxElement(const Item* i) {

	ElemType max = 0;
	const ElemType* Amax = NULL;

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), &max) == 1) {
			max = tmp->value;
			Amax = ListGetHeadValue(tmp);
		}
	}

	return Amax;
}