#include<stdlib.h>
#include<stdio.h>

static char alf[] = { 'a','b','c','d','e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v','w','x','y','z' };

void BacktrackStrModRec(int n, int k, int* vcurr, int i) {
	if (i == k) {
		fprintf(stdout,"{");
		for (int l = 0; l < i; l++) {
			fprintf(stdout, "%c", alf[vcurr[l]]);
		}
		fprintf(stdout, "}, ");
		return;
	}

	for (int j = 0; j < n; j++) {
		vcurr[i] = j;
		BacktrackStrModRec(n, k, vcurr, i + 1);
	}
}



void BacktrackStrMod(int n, int k) {
	if (n <= 0 || n > 26 || k <= 0) {
		return;
	}

	
	int* vcurr = calloc(k, sizeof(int));
	BacktrackStrModRec(n, k, vcurr, 0);
	free(vcurr);
}