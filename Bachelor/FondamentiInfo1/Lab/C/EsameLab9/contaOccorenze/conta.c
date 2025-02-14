#include<stdlib.h>
#include<string.h>

unsigned int conta_occorrenze(const char* testo, const char* stringa) {
	if (testo == NULL || stringa == NULL) return 0;
	int trovato = 0;
	int check = 0;
	int occ = 0;
	int h = 0;
	for (int i = 0; testo[i] != 0; i++) {
		if (trovato == 1) {
			h = i;
			for (int j = 1; stringa[j] != 0; j++) {
				if (testo[h] == stringa[j]) {
					check = 1;
				}
				else {
					check = 0;
					break;
				}
				h++;
			}
			if (check == 1) {
				occ++;
			}
		}
		else
		{
			if (testo[i] == stringa[0]) trovato = 1;
		}
	}
	return occ;
}