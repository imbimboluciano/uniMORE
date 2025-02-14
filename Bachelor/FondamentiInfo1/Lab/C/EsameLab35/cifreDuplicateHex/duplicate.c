#include<stdbool.h>
#include<stdlib.h>

int contacifre(unsigned int n) {
	int c = 0;
	for (int i = 0; n != 0; i++) {
		n /= 16;
		c++;
	}
	return c;
}
bool cifre_duplicate_hex(unsigned int n) {
	int x = contacifre(n);
	unsigned int* arr = calloc(x, sizeof(unsigned int));
	for (int i = 0; n != 0; i++) {
		arr[i] = n % 16;
		n /= 16;
	}
	for (int j = 0; j < x; j++) {
		for (int h = j + 1; h < x; h++) {
			if (arr[j] == arr[h]) {
				free(arr);
				return true;
			}
		}
	}
	free(arr);
	return false;
}