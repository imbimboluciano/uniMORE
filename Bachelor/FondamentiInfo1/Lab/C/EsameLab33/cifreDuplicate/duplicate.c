#include<stdbool.h>
#include<stdlib.h>

int contacifre(unsigned long long n) {
	int c = 0;
	for (int i = 0; n != 0; i++) {
		n /= 10;
		c++;
	}
	return c;
}
bool cifre_duplicate(unsigned long long n) {
	int x = contacifre(n);
	unsigned long long* arr = calloc(x, sizeof(unsigned long long));
	for (int i = 0; n != 0; i++) {
		arr[i] = n % 10;
		n /= 10;
	}
	for (int j = 0; j < x; j++) {
		for (int h = j + 1; h < x; h++) {
			if (arr[j] == arr[h]) return true;
		}
	}
	return false;
}