#include "vettore.h"

int main(void) {

	int d[] = { 1,2,3,4,5,6 };
	struct vettore v = { NULL,6 };
	v.data = d;

	Push(&v, 14);

	return 0;
}