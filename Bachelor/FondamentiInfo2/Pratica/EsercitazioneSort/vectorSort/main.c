#include "vector.h"


int main(void) {

	ElemType d[] = { 4, 34, 12, -2, 3, 4, 5, 1, 3, 4 };
	Vector v = { .capacity = 10,.size = 10,.data = NULL };
	v.data = d;


	VectorSort(&v);

	free(d);
	return 0;
}