#include<stdlib.h>

unsigned int conta_spazi(const char* s) {
	if (s != NULL) {
		unsigned int spazi = 0;
		for (int i = 0; s[i] != 0; i++) {
			if (s[i] == ' ') spazi++;
		}
		return spazi;
	}
	return 0;
}
