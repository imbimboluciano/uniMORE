#include <stdio.h>


int multip(short a, short b);

int main(void) {
	short a = 5, b = 7;
	int c = multip(5, 7);
	
	printf("%d", c);
	return 0;
}