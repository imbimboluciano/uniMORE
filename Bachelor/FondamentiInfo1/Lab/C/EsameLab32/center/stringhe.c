#include "stringhe.h"


char* center(const char* str, size_t n, char c) {
	if (str == NULL) return NULL;
	size_t l = strlen(str);
	char* res = calloc(l + 1,sizeof(char));
	size_t h = 0;
	for ( h = 0; h < l; h++) {
		res[h] = str[h];
	}
	if (n <= l) return res;
	free(res);
	res = calloc((n + 1),sizeof(char));
	size_t pun = n - l;
	size_t pin = pun / 2;
	int t = 0;
	if (l % 2 == 0 && n % 2 != 0) t = -1;
	for (size_t i = 0, j = 0; i <= n; i++) {
		if (l % 2 != 0 && n % 2 == 0) {
			if (i == n) {
				res[i] = '\n';
			}
			if (t < (int)pin) {
				res[i] = c;
				t++;
			}
			else {
				res[i] = str[j];
				j++;
				if (j == l ) {
					t = -1;
				}
			}
		}
		else if (l % 2 == 0 && n % 2 != 0) {
			if (i == n) {
				res[i] = '\n';
			}
			if (t < (int)pin) {
				res[i] = c;
				t++;
			}
			else {
				res[i] = str[j];
				j++;
				if (j == l) {
					t = 0;
				}
			}
		}
		else {
			if (i == n) {
				if (l == 0) {
					res[i - 1] = c;
					break;
				}
				else
				{
					res[i] = '\n';
				}
				
			}
			if (t < (int)pin) {
				res[i] = c;
				t++;
			}
			else {
				res[i] = str[j];
				j++;
				if (j >= l) {
					t = 0;
				}
			}
		}
	}
 	return res;
}