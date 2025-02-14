#include "list.h"
#include <math.h>

 Item* CreaDaInterni(const Item* i, double r) {

	 Item* res = ListCreateEmpty();
	 for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		 int s = pow((ListGetHeadValue(tmp)->x) - 0, 2) + pow((ListGetHeadValue(tmp)->y) - 0, 2);
		 int d = sqrt(s);
		 if (d < r) {
			 res = ListInsertBack(res, ListGetHeadValue(tmp));
		 }
	 }

	 return res;
}
