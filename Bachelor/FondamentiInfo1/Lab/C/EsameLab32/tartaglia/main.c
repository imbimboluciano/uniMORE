#include<stdlib.h>
extern unsigned int* tartaglia(unsigned int* v, size_t n);

int main(void) {
	unsigned int r[] = { 1,5,10,10,5,1 };
	unsigned int* res = tartaglia(r, 1);
	return 0;
}