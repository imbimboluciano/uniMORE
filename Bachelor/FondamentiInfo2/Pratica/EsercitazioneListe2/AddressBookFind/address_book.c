#include "list.h"
#include<string.h>

const ElemType* Find(const Item* i, const char* name) {

	const ElemType* res = NULL;

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		const char* str = ListGetHeadValue(tmp)->name;
		if (strcmp(str,name) == 0) {
			res = ListGetHeadValue(tmp);
			break;
		}
	}

	return res;
}