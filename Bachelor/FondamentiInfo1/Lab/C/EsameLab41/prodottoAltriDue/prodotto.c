#include<stdlib.h>

int prodotto_altri_due(const int* v, size_t n) {
	if (v == NULL || n == 0) return -1;
	int* vet = NULL;
	size_t npro = 0;
	int prod = 0;
	int check = 0;
	size_t np = 0;
	int isalr = 0;
	for (size_t r = 0; r < n; r++) {
		for (size_t c = 0; c < n; c++) {
			if (r == c) continue;
			prod = v[r] * v[c];
			for (size_t j = 0; j < n; j++) {
				if (prod == v[j]) {
					if (v[j] != v[r] && v[j] != v[c]) {
						if (check == 0) {
							npro++;
							vet = realloc(vet, npro * sizeof(int));
							vet[npro - 1] = prod;
							check = 1;
							break;
						}
						else {
							for (size_t k = 0; k < npro; k++) {
								if (vet[k] == prod) {
									isalr = 1;
									break;
								}
							}
							if (isalr == 1) {
								isalr = 0;
								break;
							}
							else {
								npro++;
								vet = realloc(vet, npro * sizeof(int));
								vet[npro - 1] = prod;
								isalr = 0;
							}
						}
						
					}
				}
			}
		}
	}
	free(vet);
	return npro;

}