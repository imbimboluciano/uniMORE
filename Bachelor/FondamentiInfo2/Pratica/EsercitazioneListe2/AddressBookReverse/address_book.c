#include "list.h"


Item* Reverse(const Item* i) {

	if (ListIsEmpty(i)) return NULL;

	Item* res = NULL;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		res = ListInsertHead(&tmp->value,res);
	}
	return res;
}