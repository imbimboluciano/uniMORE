#include "complessi.h"

int read_complesso(struct complesso* comp, FILE* f) {
	if (comp == NULL || f == NULL) return 0;
	int ris = 0;
	ris = fscanf(f, "%lf %lf\n", &comp->re, &comp->im);
	if (ris == -1) return 0;
	return 1;
}
void write_complesso(const struct complesso* comp, FILE* f) {
	if (comp != NULL && f != NULL) {
		fprintf(f, "%lf %lf\n", comp->re, comp->im);
	}
}
void prodotto_complesso(struct complesso* comp1, const struct complesso* comp2) {
	if (comp1 != NULL && comp2 != NULL) {
		struct complesso temp = { 0,0 };
		temp.re = (comp1->re * comp2->re) - (comp1->im * comp2->im);
		temp.im = (comp1->re * comp2->im) - (comp1->im * comp2->re);
		*comp1 = temp;
	}
}