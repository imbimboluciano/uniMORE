#include<stdlib.h>
#include<stdint.h>

void copy(uint32_t* dst, uint32_t* src, size_t n) {
	
	while (n) {
		*(dst + n - 1) = *(src + n - 1);
		n--;
	}
}