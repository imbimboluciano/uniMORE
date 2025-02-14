#include <stdio.h>

int fattoriale(int v);

int main(void) {

	int v = 10;
	int c = fattoriale(v);

	printf("%d", c);
	return 0;

}