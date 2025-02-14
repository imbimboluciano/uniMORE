#include <stdio.h>

int vettorePrimo(int* v, int lung);

int main(void) {

	int v[3] = { 6,8,7 };
	int c = vettorePrimo(v, 3);
	printf("%d", c);
	return 0;
}