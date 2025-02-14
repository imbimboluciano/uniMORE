#include "sample.h"

int sample_scrivi(FILE* f, const struct sample* s) {
	if (f == NULL || s == NULL)	return 0;
	int  ris = fprintf(f, "%d%s%lf", s->idSample, s->nomeCategoria, s->accuracy);
	if (ris == -1) return 0;
	return 1;

}

int sample_leggi(FILE* f, struct sample* s) {
	if (f == NULL || s == NULL)	return 0;
	struct sample tmp = { 0,NULL,0 };
	int ris = fscanf(f, "%d%s%lf", &tmp.idSample, &tmp.nomeCategoria, &tmp.accuracy);
	if (ris == -1) return 0;
	*s = tmp;
	return 1;

}