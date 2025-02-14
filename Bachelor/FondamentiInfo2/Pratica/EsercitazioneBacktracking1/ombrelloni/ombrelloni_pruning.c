#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

void OmbrelloniPruningRec(int k, int n, bool* vcurr, int i,int cnt, int* nsol) {


	if (cnt == k) {
		(*nsol)++;
		printf("%4d) ", *nsol);
		for (int j = 0; j < n; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}

	if (i == n) {
		return;
	}


	vcurr[i] = 0;
	OmbrelloniPruningRec(k, n, vcurr, i + 1,cnt, nsol);

	if (i == 0 || vcurr[i - 1] != 1) {
		vcurr[i] = 1;
		OmbrelloniPruningRec(k, n, vcurr, i + 1,cnt + 1, nsol);
		vcurr[i] = 0;
	}
	

}



int OmbrelloniPruning(int k, int n) {
	if (k < 0 || n < 0)	return 0;
	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;
	OmbrelloniPruningRec(k, n, vcurr, 0,0, &nsol);
	free(vcurr);
	return nsol;
}




