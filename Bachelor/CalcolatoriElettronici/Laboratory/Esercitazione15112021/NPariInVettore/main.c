#include <stdio.h>

int NumeroDiPari(unsigned char* v, int lung);

int main(void) {

	unsigned char v[6] = {1,2,3,4,5,6};
	int c = NumeroDiPari(v, 6);
	printf("%d", c);
	return 0;
}