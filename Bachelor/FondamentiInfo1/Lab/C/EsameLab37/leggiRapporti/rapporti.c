#include "rapporti.h"

struct rapporto* leggi_rapporti(const char* filename, uint16_t* n) {
	if (filename == NULL) return NULL;
	FILE* f = fopen(filename, "rb");
	if (f == NULL) return NULL;
	struct rapporto* res = NULL;
	uint16_t id;
	char tipo;
	float valore;
	size_t i = 0;
	size_t np = 0;
	fread(&np, 2, 1, f);
	while (i < (size_t) np) {
		fread(&id,sizeof(uint16_t), 1, f);
		fread(&tipo, sizeof(char), 1, f);
		fread(&valore, sizeof(float), 1, f);
		i++;
		res = realloc(res, i * sizeof(struct rapporto));
		res[i - 1].id = id;
		res[i - 1].tipo = tipo;
		res[i - 1].valore = valore;
	}

	*n = (uint16_t)np;
	fclose(f);
	return res;

}