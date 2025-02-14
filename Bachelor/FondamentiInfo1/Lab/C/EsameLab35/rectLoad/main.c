#include "shapes.h"

int main(void) {
	FILE* f = fopen("rect1.bin", "rb");
	struct rect r = { 0,0,5,3,NULL };
	bool res = rect_load(f, &r);
	res = rect_load(f, &r);
	return 0;
}