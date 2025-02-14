#include "tirocini.h"

int main(void) {
	FILE* f = fopen("input2.txt", "r");
	struct tirocinio t = { NULL,NULL,NULL,NULL };
	bool res = tirocinio_load(f, &t);
	return 0;
}