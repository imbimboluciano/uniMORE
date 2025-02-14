#include "lettura.h"

int* leggiinteri(const char* filename, size_t* size) {
	if (filename != NULL) {
		int* seq;
		int32_t n;
		FILE* f = fopen(filename, "rb");
		if (f != NULL){
			size_t temp = fread(&n,sizeof(int32_t), 1, f);

			if (temp != 1) {
				fclose(f);
				return NULL;
			}
			seq = malloc(n * sizeof(int));
			*size = (size_t)n;
			temp = fread(seq, sizeof(int), n, f);

			if (temp != (size_t)n) {
				free(seq);
				return NULL;
			}

			fclose(f);
			return seq;
		}
	}
	return NULL;
}
