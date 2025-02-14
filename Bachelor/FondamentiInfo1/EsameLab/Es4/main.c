#include "utf8.h"

int main(void) {
	uint8_t v[4];
	size_t bn = utf8_encode(0x000000a2, v);
	return 0;
}