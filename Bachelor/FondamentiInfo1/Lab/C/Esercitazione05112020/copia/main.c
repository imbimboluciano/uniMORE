#include<stdlib.h>
#include<stdint.h>

extern void copy(uint32_t *dst, uint32_t *src, size_t n); // copia di un vettore

int main(void) {
	size_t n = 3;
	uint32_t* dst = malloc(n * sizeof(uint32_t));
	uint32_t* src = malloc(n * sizeof(uint32_t));
	src[0] = 3;
	src[1] = 5;
	src[2] = 7;
	copy(dst, src, n);
	free(dst);
	free(src);
	return 0;
}