#include "images.h"

struct image* read_images(const char* filename, size_t* n) {
	FILE* f = fopen(filename, "r");
	if (f != NULL) {
		struct image* res = NULL;
		int ris = 0;
		int nr = 0;
		struct image tmp;
		while ((fscanf(f, "%254[^:]:%d:%d\n", &tmp.name, &tmp.height, &tmp.width)) == 3) {
			++nr;;
			res = realloc(res, nr * sizeof(char));
			res[nr - 1] = tmp;
		}
		*n = nr;
		fclose(f);
		return res;
	}
	
	return NULL;

	
}