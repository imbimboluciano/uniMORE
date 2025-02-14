#include<stdlib.h>
#include<stdio.h>

void StepsRec(int n,int i,int* nsol,int* vcurr,int s) {
	if (s == n) {
		(*nsol)++;
		fprintf(stdout, "[");
		for (int k = 0; k < i; k++) {
			if (k == i - 1) {
				fprintf(stdout, "%d],", vcurr[k]);
			}
			else {
				fprintf(stdout, "%d, ", vcurr[k]);
			}
		}
		return;
	}
	if (i == n) {
		return;
	}


	for (int j = 1; j <= 3; j++) {
		vcurr[i] = j;
		StepsRec(n, i + 1, nsol, vcurr, s + j);
	}
}


int Steps(int n) {
	if (n <= 0) {
		return 0;
	}
	int* vcurr = calloc(n, sizeof(int));
	int nsol = 0;
	StepsRec(n, 0, &nsol, vcurr,0);

	free(vcurr);
	return nsol;
}
