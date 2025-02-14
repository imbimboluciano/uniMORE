#include "tirocini.h"


bool tirocinio_load(FILE* f, struct tirocinio* t) {
	if (f == NULL) return false;
	t->nome = calloc(64, sizeof(char));
	t->azienda1 = calloc(64, sizeof(char));
	t->azienda2 = calloc(64, sizeof(char));
	t->azienda3 = calloc(64, sizeof(char));

	int ris = fscanf(f, "%[^,],", t->nome);
	if (ris == -1) {
		free(t->nome);
		free(t->azienda1);
		free(t->azienda2);
		free(t->azienda3);
		return false;
	}
	fscanf(f, "%[^,],", t->azienda1);
	fscanf(f, "%[^,],", t->azienda2);
	fscanf(f, "%[^\n]\n", t->azienda3);

	
	return true;
} 
