#include "list.h"

Item* ElementiPari(const Item* i) {

	Item* res = ListCreateEmpty();
	int j = 0;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j % 2 == 0) {
			res = ListInsertBack(res, ListGetHeadValue(tmp));
		}
		j++;
	}

	return res;
}