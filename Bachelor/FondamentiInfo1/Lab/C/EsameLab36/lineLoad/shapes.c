#include "shapes.h"

bool line_load(FILE* f, struct line* pln) {
	if (f == NULL || pln == NULL) return false;

	fread(&pln->x1, sizeof(int16_t),1, f);
	if (ferror(f) != 0) return false;
	if (feof(f) != 0) return true;

	fread(&pln->y1, sizeof(int16_t),1, f);
	if (ferror(f) != 0) return false;
	if (feof(f) != 0) return true;

	fread(&pln->x2, sizeof(int16_t),1, f);
	if (ferror(f) != 0) return false;
	if (feof(f) != 0) return true;

	fread(&pln->y2, sizeof(int16_t),1, f);
	if (ferror(f) != 0) return false;
	if (feof(f) != 0) return true;

	fread(&pln->thickness, sizeof(int8_t),1, f);
	if (ferror(f) != 0) return false;
	if (feof(f) != 0) return true;

	return true;


}