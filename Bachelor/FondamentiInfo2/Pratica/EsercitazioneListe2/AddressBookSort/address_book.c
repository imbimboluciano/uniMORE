#include "list.h"

Item* Sort(Item* i) {

	if (ListIsEmpty(i)) return i;
	int dim = 0;
	int ordinato = 0;
	while (dim == 0 && !ordinato) {
		ordinato = 1;
		for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			if (tmp->next != NULL) {
				if (ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(tmp->next)) > 0) {
					ElemSwap(ListGetHeadValue(tmp), ListGetHeadValue(tmp->next));
					ordinato = 0;
				}
			}
			dim++;
		}
		dim--;
	}
	return i;
}