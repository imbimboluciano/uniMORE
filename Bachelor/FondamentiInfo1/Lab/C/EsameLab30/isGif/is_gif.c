#include "is_gif.h"

bool is_gif(const char* filename) {
	if (filename == NULL) return false;
	FILE* f = fopen(filename, "r");
	if (f == NULL) return false;
	char* f6 = NULL;
	int c = 0;
	int i = 0;
	while (1) {
		c = fgetc(f);
		if (i == 6) {
			i++;
			f6 = realloc(f6,i * sizeof(char));
			f6[i-1] = '\0';
			break;
		}
		i++;
		f6 = realloc(f6,i * sizeof(char));
		f6[i-1] = c;
		
	}
	if (strcmp(f6, "GIF89a") == 0 || strcmp(f6, "GIF87a") == 0) {
		free(f6);
		fclose(f);
		return true;
	}
	free(f6);
	fclose(f);
	return false;
}
