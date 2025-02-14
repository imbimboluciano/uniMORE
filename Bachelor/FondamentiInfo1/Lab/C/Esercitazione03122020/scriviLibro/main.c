#include "libri.h"

int main(void) {

	FILE* f = fopen("file.bin", "wb");
	struct libro* l = malloc(sizeof(struct libro));
	uint16_t ristampe[] = {2001,2002,0};
	char* tit = "Geometria";
	l->titolo = tit;
	l->anni_ristampe = ristampe;
	bool x = libro_scrivi(l, f);
	free(l);
	return 0;
}