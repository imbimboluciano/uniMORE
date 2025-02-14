#include "list.h"

extern int ContaVette(const Item* i);

int main(void) {

	ElemType v[] = { 4,9,8,6 };
	Item* i = ListCreateEmpty();
	i = ListInsertBack(i, v + 0);
	i = ListInsertBack(i, v + 1);
	i = ListInsertBack(i, v + 2);
	i = ListInsertBack(i, v + 3);
	

	int res = ContaVette(i);
	return 0;
}