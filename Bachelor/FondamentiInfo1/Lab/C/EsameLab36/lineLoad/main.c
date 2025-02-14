#include "shapes.h"

int main(void) {
	FILE* f = fopen("line1.bin", "rb");
	struct line l = { 0,0,0,0,0};
	bool res = line_load(f, &l);
	res = line_load(f, &l);
	res = line_load(f, &l);
	return 0;
}