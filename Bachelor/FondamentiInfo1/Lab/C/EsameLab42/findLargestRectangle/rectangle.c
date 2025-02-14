#include "rectangle.h"

int find_largest(const struct rect* r, size_t n) {
	if (r == NULL) return -1;
	int area = 0;
	int max = 0;
	int c = 0;
	int pos = 0;
	for (size_t i = 0; i < n; i++) {
		area = abs(r[i].a.x - r[i].b.x) * abs(r[i].a.y - r[i].b.y);
		if (c == 0) {
			max = area;
			pos = i;
			c = 1;
		}
		else if (area > max) {
			max = area;
			pos = i;
		}
	}

	return pos;
}