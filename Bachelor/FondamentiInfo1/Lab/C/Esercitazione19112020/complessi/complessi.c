#include "complessi.h"

void prodotto_complesso(struct complesso* comp1, const struct complesso* comp2) {
	struct complesso box = {0,0};
	box.re = ((comp1->re * comp2->re) - (comp1->im * comp2->im));
	box.im = ((comp1->re * comp2->im) + (comp1->im * comp2->re));
	*comp1 = box;
}