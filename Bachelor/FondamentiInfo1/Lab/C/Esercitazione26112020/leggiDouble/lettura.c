#include "lettura.h"

double* leggidouble(const char* filename, size_t* size) {
	if (filename != NULL) {
		FILE* f = fopen(filename, "r");
		if (f != NULL) {
			double temp;
			size_t count = 0;
			int check;
			double* ris = malloc(1*sizeof(double));
			while (1) {
				check = fscanf(f, "%lf", &temp);
					if (check == 1) {
						count++;
						ris = realloc(ris, count * sizeof(double));
						ris[count - 1] = temp;
					}
					else {
						break;
					}
			}
			*size = count;
			if (count == 0) {
				free(ris);
				fclose(f);
				return NULL;
			}
			fclose(f);
			return ris;
		}
	}
	return NULL;
}