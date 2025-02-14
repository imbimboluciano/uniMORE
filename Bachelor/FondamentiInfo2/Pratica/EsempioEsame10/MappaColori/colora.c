#include "colora.h"

void MappaColoriRec(const struct Matrix* m, const char* c, size_t c_size,int i,int* nsol,int n,int *vcurr) {
	if (i == n) {
		int nonvabene = 0;
		for (int k = 0; k < i; k++) {
			for (int l = 0; l < i; l++) {
				if (((k * n) + l) != (k*n + k)) {
					if (m->data[k * n + l] == 1 ) {
						if (vcurr[k] == vcurr[l]) {
							nonvabene = 1;
							break;
						}
					}
				}
			}
			if (nonvabene == 1) {
				break;
			}
		}
		if (nonvabene == 0) {
			(*nsol)++;
			for (int k = 0; k < i; k++) {
				fprintf(stdout, "%d -> %c; ", k, c[vcurr[k]]);
			}
			fprintf(stdout, "\n");
		}
		
		return;
	}


	for (size_t j = 0; j < c_size; j++) {
		vcurr[i] = j;
		MappaColoriRec(m, c, c_size, i + 1, nsol, n, vcurr);
	}
}


int MappaColori(const struct Matrix* m, const char* c, size_t c_size) {

	int n = sqrt(m->size);
	int* vcurr = calloc(n, sizeof(int));
	int nsol = 0;

	MappaColoriRec(m, c, c_size, 0, &nsol, n, vcurr);
	free(vcurr);
	return nsol;
}