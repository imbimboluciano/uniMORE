#include<stdlib.h>
#include<stdbool.h>

extern bool is_arithmetic(const int* v, size_t n);

int main(void) {

	int v[] = { 3,3,3 };
	bool res = is_arithmetic(v, 3);
	return 0;
}