#include <stdio.h>

int media(int* v, int lunghezza, int *resto);

int main(void) {

	int v[10] = { 5,6,7,3,10,9,4,9,8,5 };
	int r = 0;
	int c = media(v, 10, &r);

	fprintf(stdout, "%d %d", c, r);
	return 0;
}