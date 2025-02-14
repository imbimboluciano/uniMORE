#include<stdlib.h>

char* change_font(const char* s) {
	if (s == NULL) return NULL;

	char* res = NULL;
	size_t j = 0;
	size_t i = 0;

	while (s[i] != 0) {
		if (s[i] == 'P' && s[i + 1] == 'E' && s[i + 2] == 'R') {
			j += 1;
			res = realloc(res, j * sizeof(char));
			res[j - 1] = 'X';
			i += 3;
		}
		else if(s[i] == 'S' && s[i + 1] == 'E' && s[i + 2] == 'I') {
			j += 1;
			res = realloc(res, j * sizeof(char));
			res[j - 1] = '6';
			i += 3;
		}
		else if (s[i] == 'A') {
			j += 1;
			res = realloc(res, j * sizeof(char));
			res[j - 1] = '4';
			i += 1;
		}
		else if (s[i] == 'E') {
			j += 1;
			res = realloc(res, j * sizeof(char));
			res[j - 1] = '3';
			i += 1;
		}
		else if (s[i] == 'I') {
			j += 1;
			res = realloc(res, j * sizeof(char));
			res[j - 1] = '1';
			i += 1;
		}
		else if (s[i] == 'O') {
			j += 1;
			res = realloc(res, j * sizeof(char));
			res[j - 1] = '0';
			i += 1;
		}
		else if (s[i] == 'S') {
			j += 1;
			res = realloc(res, j * sizeof(char));
			res[j - 1] = '5';
			i += 1;
		}
		else {
			j += 1;
			res = realloc(res, j * sizeof(char));
			res[j - 1] = s[i];
			i++;
		}
	}
	j++;
	res = realloc(res, j * sizeof(char));
	res[j - 1] = '\0';
	return res;
}