#include<stdlib.h>

int* convolution3(const int* v, size_t lenv, const int k[3]) {
	if (v == NULL || k == NULL) return NULL;
	int* res = calloc(lenv, sizeof(int));
	int somma = 0;
	for (int i = 0; i <(int) lenv; i++) {
		if (i < (int)lenv) {
			for (int m = 0; m < 3; m++) {
				if (((i+1)-m) < 0) {
					somma += 0 * k[m];
				}
				else if(i == (int)(lenv - 1) && m == 0) {
					somma +=  0 * k[m];
				}
				else {
					somma += v[i + 1 - m] * k[m];
				}
				
			}
			res[i] = somma;
			somma = 0;
		}
		else {
			res[i] = 0;
		}
		
	}
	return res;
}