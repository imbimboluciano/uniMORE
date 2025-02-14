#include<stdlib.h>
#include<stdint.h>

extern uint32_t* somme_2a2(uint32_t* vett, size_t size);

int main(void) {

	size_t size = 6;
	uint32_t *v = malloc(size * sizeof(uint32_t));
	v[0] = 3; v[1] = 87; v[2] = 5; v[3] = 7; v[4] = 12; v[5] = 9;
	uint32_t* somme = somme_2a2(v, size);
	free(v);
	free(somme);
	return 0;
}