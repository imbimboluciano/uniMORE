#include<stdlib.h>

extern int* slicing(const int* v, size_t* n, size_t start, size_t end, int step);

int main(void) {
	size_t n = 0;
	int v[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int* res = slicing(v,&n, 3, 6, 1);
	return 0;
}