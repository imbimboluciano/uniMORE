#include "alterna.h"

char* alterna(const char* s1, const char* s2) {
	size_t l1 = strlen(s1);
	size_t l2 = strlen(s2);
	char* s = calloc(l1 + l2 + 1,sizeof(char));
	if (l1 >= l2) {
		for (size_t i = 0,j = 0; i < l1; i++,j += 2) {
			if (i >= l2) {
				s[j] = s1[i];
				j -= 1;
			}
			else {
				s[j] = s1[i];
				s[j + 1] = s2[i];
			}
		}
	}
	else if (l2 > l1) {
		for (size_t i = 0, j = 0; i < l2; i++, j += 2) {
			if (i >= l1) {
				s[j] = s2[i];
				j -= 1;
			}
			else {
				s[j] = s1[i];
				s[j + 1] = s2[i];
			}
		}
	}
	return s;
}
