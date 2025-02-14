#include "path_split.h"

void path_split(const char* str, char** path, char** filename) {
	if (str == NULL) {
		*path = NULL;
		*filename = NULL;
	}
	size_t c = 0;
	for (size_t i = 0; str[i] != 0; i++) {
		if (str[i] == '\\') c = i;
	}
	char* f = calloc(strlen(str) - c, sizeof(char));
	char* p = calloc(c + 2, sizeof(char));
	f[0] = 0;
	p[0] = 0;
	
	for (size_t j = 0,i = 0; str[j] != 0; j++) {
		if (j <= c) {
			p[j] = str[j];
		}
		else {
			f[i] = str[j];
			i++;
		}
	}

	*filename = f;
	*path = p;
}