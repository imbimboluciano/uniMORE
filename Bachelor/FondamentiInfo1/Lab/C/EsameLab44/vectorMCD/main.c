#include<stdlib.h>
#include<stdint.h>

extern uint32_t vector_MCD(const uint32_t* v, size_t n);

int main(void) {

	uint32_t v[] = { 4,6,8,14,26 };
	uint32_t mcd = vector_MCD(v, 5);
	return 0;
}