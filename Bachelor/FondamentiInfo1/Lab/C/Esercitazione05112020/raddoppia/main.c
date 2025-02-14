#include <stdlib.h>
#include <stdint.h>

void raddoppia(uint32_t* x, size_t n)
{
	/* completare la funzione raddoppia() */
	while (n) {
		*(x + n-1) = *(x + n-1) * 2;
		n--;
	}
}

int main(void)
{
	size_t n = 5;
	uint32_t* v = malloc(n * sizeof(uint32_t));
	v[0] = 12;
	v[1] = 59;
	v[2] = 83;
	v[3] = 5;
	v[4] = 7;
	raddoppia(v, n);
	free(v);
	return 0;
}