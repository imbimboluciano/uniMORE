#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void RegoleRec(const char* r,int n,int* vcurr,int i) {
	if (i == n + 1) {
		int trovato = 0;
		int norep = 0;
		for (int k = 0; k <= i; k++) {
			if (k != 0) {
				if (r[k - 1] == 'I' || r[k - 1] == 'i') {
					if (vcurr[k] < vcurr[k - 1] ) {
						trovato = 1;
						break;
					}
				}
				else if (r[k - 1] == 'D' || r[k - 1] == 'd') {
					if (vcurr[k] > vcurr[k - 1]) {
						trovato = 1;
						break;
					}
				}
			}
		}
		for (int l = 0; l < i; l++) {
			for (int k = l + 1; k < i; k++) {
				if (vcurr[l] == vcurr[k]) {
					norep = 1;
					break;
				}
			}
		}
		if (trovato == 0 && norep == 0) {
			for (int k = 0; k < i; k++) {
				fprintf(stdout, "%d ", vcurr[k]);
			}
			fprintf(stdout, "\n");
		}
		return;
	}
	for (int j = 1; j <= n + 1; j++) {
		vcurr[i] = j;
		RegoleRec(r, n, vcurr, i + 1);
	}
}


void Regole(const char* r) {
	if (strlen(r) == 0) {
		fprintf(stdout, "1");
		return;
	}

	int* vcurr = calloc(strlen(r) + 1, sizeof(int));
	RegoleRec(r, strlen(r), vcurr, 0);
	free(vcurr);
 }