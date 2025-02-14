#include "list.h"


extern Item* CreaDaMinori(const Item* i, int v);

int main(void) {

	ElemType v[] = { 6,8,9 };
	Item* list = ListCreateEmpty();
	list = ListInsertBack(list, &v[0]);
	list = ListInsertBack(list, &v[1]);
	list = ListInsertBack(list, &v[2]);

	Item* res = CreaDaMinori(list, 7);

	return 0;
}