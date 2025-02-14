#include "list.h"
#include<string.h>

Item* Filtra(const Item* i, const char* city) {

	if (ListIsEmpty(i)) return NULL;

	Item* res = NULL;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		const char* str = ListGetHeadValue(tmp)->city;
		if (strcmp(str, city) == 0) {
			res = ListInsertBack(res, &tmp->value);
		}
	}

	return res;
}