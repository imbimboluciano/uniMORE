#include "list.h"
#include<stdlib.h>


int main(void) {

	ElemType v[] = { 4,6,9 };
	Item* i = ListCreateEmpty();
	i = ListInsertBack(i, v + 0);
	i = ListInsertBack(i, v + 1);
	i = ListInsertBack(i, v + 2);
	
	

	return 0;
}