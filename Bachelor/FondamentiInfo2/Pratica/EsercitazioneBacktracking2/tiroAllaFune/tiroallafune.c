#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>



void funeRec(int i, int* v, int n, bool* vcurr, bool* vbest, int count, int* dif) {

	if (count == n / 2) {


		int sup_dif = 0;

		for (int j = 0; j < n; j++) {
			if (vcurr[j] == 1) {
				sup_dif += v[j];
			}
			else {
				sup_dif -= v[j];
			}
		}

		if (abs(sup_dif) < *dif) {
			for (int j = 0; j < n; j++) {
				vbest[j] = vcurr[j];
			}
			*dif = abs(sup_dif);
		}
		return;
	}

	if (i == n) {

		return;
	}

	vcurr[i] = 0;
	funeRec(i + 1, v, n, vcurr, vbest, count, dif);

	if (count <= n / 2) {
		vcurr[i] = 1;
		funeRec(i + 1, v, n, vcurr, vbest, count + 1, dif);
		vcurr[i] = 0;
	}
}

void fune(int* v, int n) {

	bool* vcurr = calloc(n, sizeof(bool)); // 1 se in A, 0 se in B
	bool* vbest = calloc(n, sizeof(bool));
	int dif = INT_MAX;
	funeRec(0, v, n, vcurr, vbest, 0, &dif);


	//stampa
	printf("{");
	for (int i = 0, count = 0; i < n; i++) {

		if (vbest[i]) {
			printf(" %d", v[i]);
			count++;
			if (count != n / 2) {
				printf(",");
			}
		}

	}
	printf(" },");

	printf(" {");
	for (int i = 0, count = 0; i < n; i++) {

		if (!vbest[i]) {
			printf(" %d", v[i]);
			count++;
			if (count != n - n / 2) {
				printf(",");
			}
		}

	}
	printf(" }");

	free(vcurr);
	free(vbest);
}


int main(int argc, char** argv) {

	int* v = malloc(argc * sizeof(int));

	for (int i = 1; i < argc; i++) {
		v[i - 1] = atol(argv[i]);
	}

	fune(v, argc - 1);

	return 0;
}