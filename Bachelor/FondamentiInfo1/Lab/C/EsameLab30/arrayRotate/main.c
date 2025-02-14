#include<stdlib.h>

extern int* rotate(const int* vec, size_t len, size_t r);

int main(void) {
	int vec[] = { 1,2,3,4 };
	int* res = rotate(vec, 4, 2);
	free(res);
	return 0;
}