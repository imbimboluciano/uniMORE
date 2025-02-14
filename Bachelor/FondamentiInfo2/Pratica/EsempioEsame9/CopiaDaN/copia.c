#include "list.h"

Item* CopiaDaN(const Item* i, int n) {
	
	Item* res = ListCreateEmpty();
	int j = 1;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j >= n) {
			res = ListInsertBack(res,ListGetHeadValue(tmp));
		}
		j++;
	}

	return res;
}

