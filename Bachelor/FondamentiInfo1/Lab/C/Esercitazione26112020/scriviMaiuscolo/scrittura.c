#include "scrittura.h"

int scrivimaiuscolo(const char* filename) {
	if (filename != NULL) {
		FILE* f = fopen(filename, "r");
		if (f != NULL) {
			int c;
			while (1) {
				c = fgetc(f);
				if (c == EOF) break;
				fprintf(stdout, "%c", toupper(c));
			}
			fclose(f);
			return 1;
		}
	}
	return 0;
}