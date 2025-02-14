#include "variant.h"

int main(void) {
	FILE* f = fopen("file1.variant", "rb");
	if (f == NULL) return 0;
	char type;
	read_variant(f, &type);
	fclose(f);
	return 0;
}