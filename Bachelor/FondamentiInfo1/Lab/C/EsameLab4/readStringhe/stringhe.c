#include "stringhe.h"


struct stringa* read_stringhe_bin(const char* filename, unsigned int* pn) {
	if (filename == NULL)	return NULL;
	FILE* f = fopen(filename, "rb");
	if (f == NULL)	return NULL;
	
	struct stringa* res = malloc(sizeof(struct stringa));
	struct stringa tmp;
	size_t j = 0;
	char ctmp;

	while (1) {
		fread(&tmp.length, sizeof(char), 1, f);
		if (feof(f) != 0) break;
		tmp.s = calloc(tmp.length + 1, sizeof(char));
		for (size_t i = 0; i <= tmp.length; i++) {
			if (i == tmp.length) {
				tmp.s[i] = '\0';

			}
			else {
				fread(&ctmp, sizeof(char), 1, f);
				tmp.s[i] = ctmp;

			}	
		}
		j++;
		res = realloc(res, j * sizeof(struct stringa));
		res[j - 1] = tmp;
	}

	*pn = j;
	fclose(f);
	return res;


}