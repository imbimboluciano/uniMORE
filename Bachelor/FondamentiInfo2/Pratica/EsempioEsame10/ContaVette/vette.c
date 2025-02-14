#include "list.h"

int ContaVette(const Item* i) {

	int conta = 0;
	int yes = 1;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		for (const Item* box = ListGetTail(tmp); !ListIsEmpty(box); box = ListGetTail(box)) {
			if (ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(box)) <= 0) {
				yes = 0;
			}
		}

		if (yes == 1) {
			conta++;
		}

		yes = 1;
	}
	return conta ;
}