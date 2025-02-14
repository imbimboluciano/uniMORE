#include "list.h"


Item* IntersectNoRep(const Item* i1, const Item* i2) {

	int already = 0;
	Item* ris = ListCreateEmpty();
	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (const Item* box1 = ris; !ListIsEmpty(box1); box1 = ListGetTail(box1)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(box1)) == 0) {
				already = 1;
				break;
			}
		}
		if (!already) {
			for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
				if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
					ris = ListInsertBack(ris, ListGetHeadValue(tmp1));
					break;
				}
			}
		}

		already = 0;
		
	}
	return ris;
}

Item* DiffNoRep(const Item* i1, const Item* i2) {

	Item* res = NULL;
	int trovato = 0;
	int already = 0;

	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {

		for (const Item* box1 = res; !ListIsEmpty(box1); box1 = ListGetTail(box1)) {
			if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(box1)) == 0) {
				already = 1;
				break;
			}
		}
		if (!already) {
			for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
				if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
					trovato = 1;
					break;
				}
			}
			if (!trovato) {
				res = ListInsertBack(res, &tmp1->value);
			}
			trovato = 0;
		}

		already = 0;
	}

	return res;
}