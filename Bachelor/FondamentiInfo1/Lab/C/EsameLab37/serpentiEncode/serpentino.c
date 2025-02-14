#include<stdlib.h>
#include<ctype.h>

int isvowel(int ch)
{
	int c = toupper(ch);

	return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

char* serpentino_encode(const char* s){
	if (s == NULL) return NULL;
	char* res = NULL;
	size_t i = 0;
	size_t j = 0;
	size_t h = i;
	int prima = 0;
	while (1){
		if (s[i] == 0) {
			h++;
			res = realloc(res, h * sizeof(char));
			res[h - 1] = '\0';
			break;
		}
		if (isvowel(s[i]) != 0) {
			j = i;
			if (prima == 0) {
				h = i;
				prima = 1;
			}
			h += 3;
			res = realloc(res, h * sizeof(char));
			res[h - 3] = s[j];
			res[h - 2] = 's';
			res[h - 1] = s[j];
			i++;
		}
		else {
			i++;
			h++;
			res = realloc(res, h * sizeof(char));
			res[h - 1] = s[i - 1];
		}

	}
	return res;
}