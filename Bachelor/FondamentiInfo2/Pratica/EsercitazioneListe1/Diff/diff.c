#include "list.h"

Item* Diff(const Item* i1, const Item* i2) {

	Item* res = NULL;
	int trovato = 0;

	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		for (const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1),ListGetHeadValue(tmp2)) == 0){
				trovato = 1;
				break;
			}
		}
		if(!trovato){
			res = ListInsertBack(res,&tmp1->value);
		}
		trovato = 0;
	}

	return res;
}