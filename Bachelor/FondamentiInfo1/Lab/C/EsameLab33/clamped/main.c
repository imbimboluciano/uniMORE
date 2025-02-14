#include<stdlib.h>
extern int* clamped(const int* v, size_t n, int min, int max);

int main(void) {
	int v[] = { 5,7,3,2,9 };
	int* res = clamped(v, 5, 2, 9);
	return 0;
}