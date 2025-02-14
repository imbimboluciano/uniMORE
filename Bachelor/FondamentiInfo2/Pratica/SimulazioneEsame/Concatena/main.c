#include "list.h"
#include<stdlib.h>

extern Item* ConcatenaN(Item** v, size_t v_size);

int main(void) {

	ElemType v[] = { 4,6,9 };
	ElemType v2[] = { 2,7,4 };
	Item** i = calloc(3,sizeof(Item*)) ;
	i[0] = ListCreateEmpty();
	i[1] = ListCreateEmpty();
	i[0] = ListInsertBack(i[0], v + 0);
	i[0] = ListInsertBack(i[0], v + 1);
	i[0] = ListInsertBack(i[0], v + 2);
	i[2] = ListInsertBack(i[2], v2 + 0);
	i[2] = ListInsertBack(i[2], v2 + 1);
	i[2] = ListInsertBack(i[2], v2 + 2);

	Item* res = ConcatenaN(i, 3);

	return 0;
}