#include "torrecartoni.h"

void TorreCartoniRec(const Cartone* c, size_t n,unsigned int *vcurr,int i,int sommaHNow,int sommaPNow,int* sommaHbest,unsigned int *vbest,int* num) {


	for (int j = 0; j < i - 1; j++) {
		if (vcurr[j] == vcurr[i - 1]) {
			return;
		}
		
	}

	if (i == 1) {
		sommaHNow += c[vcurr[i - 1]].a;
		sommaPNow += c[vcurr[i - 1]].p;
	}
	else if(i > 1){
		if ((int)c[vcurr[i - 1]].l >= sommaPNow) {
			sommaHNow += c[vcurr[i - 1]].a;
			sommaPNow += c[vcurr[i - 1]].p;
			if (sommaHNow > *sommaHbest) {
				*sommaHbest = sommaHNow;
				for (int k = 0; k < i; k++) {
					vbest[k] = vcurr[k];
				
				}
				*num = i;
			}
		}
		else {
			return;
		}
	}

	if (i == (int)n) {
		return;
	}


	for (int k = 0; k < (int)n; k++) {
		vcurr[i] = k;
		TorreCartoniRec(c, n, vcurr, i + 1,sommaHNow,sommaPNow,sommaHbest,vbest,num);
	}
	
}



void TorreCartoni(const Cartone* c, size_t n) {
	if (n > 0) {
		unsigned int* vcurr = calloc(n, sizeof(unsigned int));
		unsigned int* vbest = calloc(n, sizeof(unsigned int));
		int bestH = 0;
		int num = 0;
		TorreCartoniRec(c, n, vcurr,0,0,0,&bestH,vbest,&num);

		for (int i = 0; i < num; i++) {
			fprintf(stdout, "%d\n", vbest[i]);
		}

		fprintf(stdout, "Altezza: %d", bestH);

		free(vcurr);
		free(vbest);
	}
	

	


}
