#include "stringhe.h"


char* spacefill(const char* str, size_t n) {
	if (str == NULL) return NULL;
	size_t l = strlen(str);
	if (n < l) {
		char* res = calloc(l + 1, sizeof(char));
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
		if (i < n - l) {
			res[i] = ' ';
		}
		else {
			res[i] = str[j];
			j++;
		}
	}
	return res;
}