#include "rle.h"

bool easy_rle_decode(const char* nomefilein, const char* nomefileout) {
	FILE* in = fopen(nomefilein, "rb");
	if (in == NULL) return false;
	FILE* out = fopen(nomefileout, "wb");
	if (out == NULL) return false;

	uint8_t n = 0;
	char k;

	while (1) {
		fread(&n, sizeof(uint8_t), 1, in);
		if (feof(in) != 0) break;
		fread(&k, sizeof(char), 1, in);
		for (int i = 0; i < n + 1; i++) {
			fwrite(&k, sizeof(char), 1, out);
		}

	}
	fclose(in);
	fclose(out);
	return true;
}