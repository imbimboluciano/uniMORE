#include "list.h"

Item* Sum(const Item* i1, const Item* i2) {
	Item* l3 = ListCreateEmpty();
	int riporto = 0;
	ElemType sum = 0;
	const Item* box = i2;
	const Item* tmp = i1;
	while ( !ListIsEmpty(tmp) || !ListIsEmpty(box) ) {
		if (ListIsEmpty(box)) {
			sum = *ListGetHeadValue(tmp) + riporto;
		}
		else if (ListIsEmpty(tmp)) {
			sum = *ListGetHeadValue(box) + riporto;
		}
		else {
			sum = *ListGetHeadValue(tmp) + *ListGetHeadValue(box) + riporto;
		}


		if (sum >= 10) {
			sum = sum % 10;
			riporto = 1;
			l3 = ListInsertBack(l3, &sum);
		}
		else {
			riporto = 0;
			l3 = ListInsertBack(l3, &sum);
		}

		if (!ListIsEmpty(box)) {
			box = ListGetTail(box);
		}

		if (!ListIsEmpty(tmp)) {
			tmp = ListGetTail(tmp);
		}
		
	}
	if (riporto > 0) {
		l3 = ListInsertBack(l3, &riporto);
	}


	

	return l3;
}

