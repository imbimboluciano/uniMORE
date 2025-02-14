#include "shapes.h"

bool rect_load(FILE* f, struct rect* r) {
	if (f == NULL || r == NULL) return false;

	fread(&r->x, sizeof(int16_t), 1, f);
	if (feof(f) != 0) return false;
	fread(&r->y, sizeof(int16_t), 1, f);
	fread(&r->width, sizeof(uint16_t), 1, f);
	fread(&r->height, sizeof(uint16_t), 1, f);
	fread(&r->symbol, sizeof(char), 1, f);

	return true;
}