#include "list.h"
#include<stdlib.h>

Item* AppendMod(Item* i1, Item* i2) {

	if (ListIsEmpty(i1) )	return i2;

	if (ListIsEmpty(i2))	return i1;

	Item* tmp = i1;

	while (!ListIsEmpty(ListGetTail(i1))) {
		i1 = ListGetTail(i1);
	}
	i1->next = i2;

	return tmp;
}