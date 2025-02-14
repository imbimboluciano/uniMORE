#include "list.h"

/*Item* Intersect(const Item* i1, const Item* i2) {

	Item* res = NULL;

	for (const Item* box1 = i1; box1;box1 = box1->next) {
		for (const Item* box2 = i2; box2;box2 = box2->next) {
			if (box1->value == box2->value) {
				res = ListInsertBack(res, &box1->value);
				break;
			}
		}
	}
	return res;
}*/

Item* Intersect(const Item* i1, const Item* i2) {
	Item* ris = ListCreateEmpty();
	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
				ris = ListInsertBack(ris, ListGetHeadValue(tmp1));
				break;
			}
		}
	}
	return ris;
}