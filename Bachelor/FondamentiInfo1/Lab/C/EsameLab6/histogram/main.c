#include<stdlib.h>
extern void histogram(const char* values, size_t n);

int main(void) {
	char val[] = { 1,2,3 };
	histogram(val,3);
	return 0;
}