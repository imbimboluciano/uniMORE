#include <stdlib.h>
#include <stdint.h>

/* Scrivere qui la funzione raddoppia_tre() */
void raddoppia_tre(uint32_t *v) {
	for (size_t i = 0; i <= 3; ++i) {
		*(v + i) = *(v + i) * 3;
	}
}

int main(void)
{
	uint32_t *v = malloc(3 * sizeof(uint32_t));
	v[0] = 12;
	v[1] = 59;
	v[2] = 83;
	raddoppia_tre(v);
	free(v);
	return 0;
}