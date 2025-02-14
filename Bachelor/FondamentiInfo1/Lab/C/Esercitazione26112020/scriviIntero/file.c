#define _CRT_SECURE_NO_WARNINGS
#include<stdbool.h>
#include <stdio.h>

bool scrivi_intero(const char* filename, int i) {
	if (filename != NULL) {
		FILE* f = fopen(filename, "wb");
		if (f != NULL) {
			if (fwrite(&i, sizeof(int), 1, f))
			{
				fclose(f);
				return true;
			}
			fclose(f);
			return true;
		}
	}
	return false;
}
