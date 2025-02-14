#include "dati.h"

struct dato* read_dati(const char* filename, unsigned int* pn) {
	FILE* f = fopen(filename,"r");
	if (f == NULL) return NULL;
	struct dato* dt = NULL;
	struct dato tmp;
	unsigned int l = 0;
	int ris = 0;
	while (1){
		ris = fscanf(f, "%lf %u\n", &tmp.valore, &tmp.classe);
		if (ris == -1) break;
		l++;
		dt = realloc(dt, l * sizeof(struct dato));
		dt[l - 1] = tmp;
	}
	*pn = l;
	fclose(f);
	return dt;
}