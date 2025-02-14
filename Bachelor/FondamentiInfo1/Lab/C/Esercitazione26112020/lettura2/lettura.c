#include "lettura.h"


int* leggiinteri2(const char* filename, size_t* size)
{
	if (filename == NULL)
	{
		return NULL;
	}
	FILE* f = fopen(filename, "rb");
	if (f == NULL)
	{
		return NULL;
	}
	int32_t temp;
	size_t n = 0;
	int t;
	int* ris = malloc(0);
	while (1)
	{
		t = fread(&temp, sizeof(int32_t), 1, f);
		if (t == 1)
		{
			n++;
			ris = realloc(ris, n * sizeof(int32_t));
			ris[n - 1] = temp;
		}
		else
		{
			break;
		}
	}
	*size = n;
	if (n == 0)
	{
		free(ris);
		fclose(f);
		return NULL;
	}
	fclose(f);
	return ris;
}