#include "libri.h"

int main(void) {
	unsigned int n = 3;
	struct libro l[] = { {23875,"L'uomo che piantava gli alberi (Salani Ragazzi)",64},
		{76890,"L'arte dell'hacking - volume 1 (Pocket) ",336},
		{12374,"Piccolo manuale della sicurezza informatica (Pocket) ",204} };
	struct libro* res = filtra_libri(l,&n,"del");
	return 0;
}