#include<stdlib.h>
#include<stdio.h>


void SubsetEqualRec(int n, int s, int i,int sommacurr,int *vcurr,int* vn) {
	if (sommacurr == s) {
		fprintf(stdout, "{ ");
		for (int j = 0; j < i; j++) {
			if (vcurr[j] == 1) {
				fprintf(stdout, "%d ", vn[j]);
			}
		}
		fprintf(stdout, "}, ");
		return;
	}
	if (i == n)	return;

	
	
	vcurr[i] = 0;
	SubsetEqualRec(n, s, i + 1, sommacurr, vcurr, vn);

	vcurr[i] = 1;
	SubsetEqualRec(n, s, i + 1, sommacurr + vn[i], vcurr, vn);

}


void SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0) {
		return;
	}

	int* vcurr = calloc(n, sizeof(int));
	int* vn = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		vn[i] = i + 1;
	}

	SubsetEqualRec(n, s, 0, 0, vcurr, vn);


}