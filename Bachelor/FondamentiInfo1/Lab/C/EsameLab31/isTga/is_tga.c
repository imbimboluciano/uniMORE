#include "is_tga.h"

bool is_tga(const char* filename) {
	if (filename == NULL) return false;
	FILE* f = fopen(filename, "rb");
	if (f == NULL) return false;

	char k;
	int i = 0;
	while (1) {
		fread(&k, sizeof(char), 1, f);
		if (feof(f) != 0)	break;
		i++;
	}
	char* s = NULL;
	int h = 0;
	rewind(f);
	fseek(f, i - 18, SEEK_SET);
	while(1){
		fread(&k, sizeof(char), 1, f);
		if (feof(f) != 0)	break;
		h++;
		s = realloc(s,h * sizeof(char));
		s[h - 1] = k;
	}
	h++;
	s = realloc(s, h * sizeof(char));
	s[h - 1] = '\0';
	if (strcmp(s, "TRUEVISION-XFILE.\0") == 0) {
		free(s);
		fclose(f);
		return true;
	}
	fclose(f);
	free(s);
	return false;
}
