#include "variant.h"

void* read_variant(FILE* f, char* type) {

	void* res = NULL;
	fread(type, sizeof(char), 1, f);
	if (feof(f) != 0)	return NULL;
	switch (*type)
	{
		case 'c':
			res = realloc(res,sizeof(char));
			fread(res, sizeof(char), 1, f);
			break;
		case 's':  res = realloc(res, sizeof(short));
			fread(res, sizeof(short), 1, f);
			break;
		case 'i':  res = realloc(res, sizeof(int));
			fread(res, sizeof(int), 1, f);
			break;
		case 'l': res = realloc(res, sizeof(long long));
			fread(res, sizeof(long long), 1, f);
			break;
		case 'f':  res = realloc(res, sizeof(float));
			fread(res, sizeof(float), 1, f);
			break;
		case 'd':  res = realloc(res, sizeof(double));
			fread(res, sizeof(double), 1, f);
			break;
		default:	return NULL;
			break;
	}
	
	return res;
}