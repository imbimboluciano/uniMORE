#include<stdlib.h>


void RecamanRec(int n, int* an,int i) {
	if (i == n) {
		return;
	}

	if (i == 0) {
		an[i] = 1;
		RecamanRec(n, an, i + 1);
	}
	else {
		if ((an[i - 1] % i) == 0) {
			an[i] = an[i - 1] / i;
			RecamanRec(n, an, i + 1);
		}
		else {
			an[i] = i* an[i - 1];
			RecamanRec(n, an, i + 1);
		}
	}
}


int Recaman(int n) {
	if (n < 1) {
		return -1;
	}
	int* res = calloc(n, sizeof(int));
	RecamanRec(n, res,0);
	int r = res[n - 1];
	free(res);
	return r;
}