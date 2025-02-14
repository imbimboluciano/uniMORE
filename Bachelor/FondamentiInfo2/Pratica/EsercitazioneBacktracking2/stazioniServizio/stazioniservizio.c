#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

void StazioniServizioRec(double m, const double* d, const double* p, size_t n,bool *vcurr,bool *vbest,int i,double dist,double percorsoDaUltimoRif,double costoNow,double *costoBest ) {

	if (dist + 600 - percorsoDaUltimoRif >= m) {  // abbiamo percorso gli m chilometri

		if (costoNow < *costoBest || *costoBest == 0) {
			*costoBest = costoNow;

			costoNow = 0;
			memcpy(vbest, vcurr,n);
		}

		return;
	}
	if (i == (int)n) {
		return;
	}
	
	dist += d[i];
	percorsoDaUltimoRif += d[i];

	if (i< n - 1 && percorsoDaUltimoRif + d[i+1] <= 600) { // non è possibile raggiungere la prossina  stazione di servizio
		vcurr[i] = 0;
		StazioniServizioRec(m, d, p, n, vcurr, vbest, i + 1, dist, percorsoDaUltimoRif, costoNow, costoBest);
	}

	if (percorsoDaUltimoRif < 600) {
		costoNow += percorsoDaUltimoRif * 0.05 * p[i];
		vcurr[i] = 1;
		percorsoDaUltimoRif = 0;
		StazioniServizioRec(m, d, p, n, vcurr, vbest, i + 1, dist, percorsoDaUltimoRif, costoNow, costoBest);
	}
	

	

}



void StazioniServizio(double m, const double* d, const double* p, size_t n) {

	bool* vcurr = calloc(n, sizeof(bool));
	bool* vbest = calloc(n, sizeof(bool));

	double costoBest = 0;
	StazioniServizioRec(m, d, p, n, vcurr,vbest,0,0,0,0,&costoBest);

	

	if (costoBest == 0) {
		fprintf(stdout, "Non esistoni soluzioni");
	}
	else {
		for (int i = 0; i < (int)n; i++) {
			if (vbest[i] == 1) {
				fprintf(stdout, "%d ", i);
			}
		}
		fprintf(stdout, "\n");
		fprintf(stdout, "Spesa totale: %lf", costoBest);
	}
	

	free(vcurr);
	free(vbest);

}