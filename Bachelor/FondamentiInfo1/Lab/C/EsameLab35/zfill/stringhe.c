#include "stringhe.h"

char* zfill(const char* str, size_t n) {
	if (str == NULL) return NULL;
	size_t l = strlen(str);
	if (l > n) {
		char* res = calloc(l+1, sizeof(char));
		for (size_t i = 0; i <= l; i++) {
			if (i == l) {
				res[i] = '\0';
			}
			else {
				res[i] = str[i];
			}
		}
		return res;
	}

	char* res = calloc(n + 1, sizeof(char));
	for (size_t i = 0,j = 0; i < n; i++) {
		if (i >= n - l) {
			res[i] = str[j];
			j++;
		}
		else {
			res[i] = '0';
		}
	}

	return res;
}