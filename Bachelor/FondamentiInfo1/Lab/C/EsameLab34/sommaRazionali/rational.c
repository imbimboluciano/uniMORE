#include "rational.h"

int MCD(int x,unsigned int y) {
	while (x != (int) y) { 
		if (x >(int) y) x = x - y;
		else y = y - x;
	}
	return x;
}


void rational_sum(struct rational* sum, const struct rational* first, const struct rational* second) {

	sum->num = (first->num * second->den) + (first->den * second->num);
	sum->den = first->den * second->den;
	if (sum->num == 0) {
		sum->num = 0;
		sum->den = 1;
	}
	else {
		int tempn = sum->num;
		int tempd = sum->den;
		int mcd = MCD(tempn, tempd);
		sum->num = sum->num / mcd;
		sum->den = sum->den / mcd;
	}
}
