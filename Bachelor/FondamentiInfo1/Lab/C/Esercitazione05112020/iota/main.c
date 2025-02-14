#include<stdlib.h>
#include<stdint.h>

extern void iota(uint32_t *x, size_t n);

int main(void) {

	size_t n = 3;
	uint32_t *x = malloc(n * sizeof(uint32_t));
	iota(x, n);
	free(x);
	return 0;
}