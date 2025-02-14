#include<stdlib.h>

int roll_and_keep(const int* r, size_t x, size_t y) {
	if (r == NULL || x == 0 || y > x || y == 0) return 0;

	int c = 0;
	int max;
	size_t pos_max;
	for (size_t i = 0; i < x; i++) {
		if (c == 0) {
			max = r[i];
			pos_max = i;
			c = 1;
		}
		else {
			if (r[i] > max) {
				max = r[i];
				pos_max = i;
			}
		}

	}
	int* res = calloc(y, sizeof(int));
	res[0] = max;
	size_t j = 1;
	for (size_t c = max; j < y; c--) {
		for (size_t i = 0; i < x; i++) {
			if (r[i] == (int)c) {
				if (i != pos_max) {
					res[j] = r[i];
					j++;
					if (j == y) break;
				}
			}
		}
	}

	int somma = 0;
	for (size_t i = 0; i < j; i++) {
		somma += res[i];
	}
	free(res);
	return somma;
	


}