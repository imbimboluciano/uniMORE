#include "libri.h"

int main(void) {
	unsigned int n = 0;
	struct libro* l = read_libri("libri1.txt", &n);
	free(l);
	return 0;
}