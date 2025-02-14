#include "matrix.h"


int main(void) {
	double d[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	struct matrix a = { 2,3,NULL };
	a.data = d;
	
	struct matrix* res = mat_rendiquadrata(&a);
	free(res->data);
	free(res);
	return 0;


}