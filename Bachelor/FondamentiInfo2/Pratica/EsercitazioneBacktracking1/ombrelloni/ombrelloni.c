#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

void OmbrelloniRec(int k, int n, bool* vcurr, int i, int* nsol) {
	
	if (i == n) {
		int cnt = vcurr[0];
		for (int j = 1; j < n; j++) {
			if (vcurr[j]) {
				cnt++;
			}
			if (vcurr[j] && vcurr[j - 1]) {
				return;
			}
		}

		if (cnt == k) {
			 /*int trovato = 0;
			for (int j = 0; j < n; j++) {
				if (vcurr[j] == 1 && vcurr[j + 1] == 1) {
					trovato = 1;
					break;
				}
			} */

			(*nsol)++;
			printf("%4d) ", *nsol);				// if (*nsol < 10) printf("    %d) ", *nsol);
												// else printf("   %d) ", *nsol);
			for (int j = 0; j < n; j++) {
				printf("%d ", vcurr[j]);
			}
			printf("\n");
		}
		return;
	}
	
	
	vcurr[i] = 0;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol);

	vcurr[i] = 1;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol);

}



int Ombrelloni(int k,int n) {
	if (k < 0 || n < 0)	return 0;
	bool* vcurr = calloc(n,sizeof(bool));
	int nsol = 0;
	OmbrelloniRec(k,n,vcurr,0,&nsol);
	free(vcurr);
	return nsol;
}




