#include "libri.h"

struct libro* read_libri(const char* filename, unsigned int* pn) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) return NULL;
	unsigned int i = 0;
	int j = 0;
	int c = 0;
	struct libro* res = NULL;
	struct libro tmp;
	int ris;
	while (1) {
		j = 0;
		ris = fscanf(f, "%u;", &tmp.codice);
		if (ris == -1) break;
		while ((c = fgetc(f)) != 59) {
			tmp.titolo[j] = c;
			j++;
		}
		ris = fscanf(f, "%u\n;", &tmp.pagine);
		if (ris == -1) break;
		i++;
		res = realloc(res, i * sizeof(struct libro));
		res[i - 1] = tmp;
	}
	*pn = i;
	fclose(f);
	return res;
}