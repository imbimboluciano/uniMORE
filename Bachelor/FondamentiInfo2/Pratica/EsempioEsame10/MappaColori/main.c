#include "colora.h"


int main(void) {

	char  c[] = { 'r','v'};
	struct Matrix m = { .size = 9 , .data = NULL };
	bool d[] = {1,1,1,1,1,0,1,0,1};
	m.data = d;
	int res = MappaColori(&m, c, 2);
	fprintf(stdout,"%d", res);
	return 0;
}