#include "libri.h"

struct libro* filtra_libri(struct libro* plibri, unsigned int* pn, const char* cerca) {
	unsigned int i = 0;
	int j = 0;
	char* p;
	struct libro* res = NULL;
	char* tmp;
	while(1){
		if (i == *pn) break;
		tmp = plibri[i].titolo;
		p = strstr(tmp, cerca);
		if (p != NULL) {
			j++;
			res = realloc(res, j * sizeof(struct libro));
			res[j - 1] = plibri[i];
		}
		i++;
	}
	*pn = j;
	return res;
}