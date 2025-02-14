#include "prezzo.h"


void TrovaArticoliRec(const struct Articolo* a, size_t n, int sum,size_t i,int *vcurr,int currsum) {
	if (currsum == sum) {
		for (size_t k = 0; k < i; k++) {
			if (vcurr[k] == 1) {
				fprintf(stdout, "%s, ", a[k].nome);
			}	
		}
		fprintf(stdout, "\n");
		return;
	}


	if (i == n) {
		return;
	}


	vcurr[i] = 0;
	TrovaArticoliRec(a, n, sum, i + 1, vcurr,currsum);

	vcurr[i] = 1;
	TrovaArticoliRec(a, n, sum, i + 1, vcurr,currsum + a[i].prezzo);
}


void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum) {

	int* vcurr = calloc(a_size, sizeof(int));

	TrovaArticoliRec(a, a_size, sum, 0, vcurr,0);
	free(vcurr);


 }