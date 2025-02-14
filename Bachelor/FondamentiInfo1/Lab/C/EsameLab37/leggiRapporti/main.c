#include "rapporti.h"

int main(void) {
	uint16_t n = 0;
	struct rapporto* r = leggi_rapporti("rapporto1.bin", &n);
	return 0;
}