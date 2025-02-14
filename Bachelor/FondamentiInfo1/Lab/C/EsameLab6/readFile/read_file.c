#include "read_file.h"

byte* read_file(const char* szFileName, size_t* cb) {
	if (szFileName == NULL) return NULL;
	FILE* f = fopen(szFileName, "rb");
	if (f == NULL) return NULL;
	byte* r = NULL;
	byte* c = calloc(1, 1);
	size_t i = 0;
	while (1) {
		i++;
		r = realloc(r, i * sizeof(byte));
		fread(c,sizeof(byte), 1, f);
		if (feof(f) != 0) {
			r[i - 1] = '\0';
			break;
		} 
		r[i - 1] = *c;
	}
	*cb = i;
	free(c);
	fclose(f);
	return r;
}