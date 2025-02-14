#include<stdlib.h>
#include<stdint.h>

uint32_t* somme_2a2(uint32_t* vett, size_t size) {
	if (vett != NULL) {
	uint32_t* s = malloc((size / 2) * sizeof(uint32_t));
		if (!(size % 2)) {
			while (size) {
				*(s + (size / 2) - 1) = *(vett + size - 1) + *(vett + size - 2);
				size = size - 2;
			}
			return s;
		}
		else {
			size = size - 1;
			while (size) {
				*(s + (size / 2) - 1) = *(vett + size - 1) + *(vett + size - 2);
				size = size - 2;
			}
			return s;
		}
	}
	return NULL;
}