#include "libri.h"

bool libro_scrivi(const struct libro* p, FILE* f) {
	if (f != NULL && p != NULL) {
		uint16_t* anni = p->anni_ristampe;
		char* titolo = p->titolo;
		if (fwrite(titolo, 1, strlen(titolo), f) != strlen(titolo))
			return false;
		char c = 0;
		if (fwrite(&c, 1, 1, f) != 1)
			return false;
		for (int i = 0; ; i++)
		{
			if (fwrite(&anni[i], sizeof(uint16_t), 1, f) != 1)
			{
				return false;
			}
			if (anni[i] == 0)
				break;
		}
		return true;
	}
	return false;
}