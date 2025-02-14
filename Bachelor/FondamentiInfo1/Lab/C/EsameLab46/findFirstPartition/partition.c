#include<stdlib.h>

size_t find_first_partition(const int* seq, size_t n) {
	if (seq == NULL || n == 0) return 0;

	int pos = n;
	int maggiore = 1;
	int minore = 1;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < i; j++) {
			if (seq[i] <= seq[j]) {
				maggiore = 0;
				break;
			}
		}

		for (size_t k = i + 1; k < n; k++) {
			if (seq[i] >= seq[k]) {
				minore = 0;
				break;
			}
		}


		if (maggiore == 1 && minore == 1) {
			pos = i;
			break;
		}
		else {
			maggiore = 1;
			minore = 1;
		}
	}

	return pos;
}

