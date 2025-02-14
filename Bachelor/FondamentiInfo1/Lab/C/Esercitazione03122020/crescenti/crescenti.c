#include<stdbool.h>
#include<stdlib.h>

int contacifre(unsigned int x) {
	int n = 0;
	for (int i = 0; x != 0; i++) {
		x /= 10;
		n++;
	}
	return n;
}

bool crescente(unsigned int x) {
	int n = contacifre(x);
	if (n == 1) return true;
	unsigned int* d = calloc(n,sizeof(unsigned int));
	unsigned int box = x;
	for (int i = 0; i < n; i++) {
		d[i] = box % 10;
		box /= 10;
	}
	for (int j = 0; j < n; j++) {
		if (j + 1 == n) {
			free(d);
			return true;
		}
		if (d[j] <= d[j + 1]) {
			free(d);
			return false;
		}
	}
	free(d);
	return false;
 }