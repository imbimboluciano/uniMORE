#include<stdlib.h>
#include<stdint.h>

void iota(uint32_t* x, size_t n) {
	if (x != NULL) {
		while (n) {
			*(x + n - 1) = n - 1;
			n--;
		}
	}
}
