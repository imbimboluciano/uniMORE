#include "vector.h"


int main(void) {

	ElemType e = 3;
	ElemType d[] = { -12, -4, 3, 3, 3, 3, 4, 5, 6, 6, 7, 8, 34, 34, 54, 56, 234, 346, 367, 435, 1233, 3453, 3456, 4567, 5667 };
	Vector v = { .capacity = 25,.size = 25, .data = NULL };
	v.data = d;

	int res = VectorFind(&v, &e);

	free(d);
	return 0;
}