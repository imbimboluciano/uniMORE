#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char* hangman(const char* frase, const char* lettere) {
	if (frase == NULL)	return NULL;
	size_t l = strlen(frase);
	char* res = calloc(l + 1, sizeof(char));
	int trovato = 0;
	size_t i;
	for (i = 0; frase[i] != 0; i++) {

		for (size_t j = 0; lettere[j]; j++) {
			if (frase[i] == lettere[j] || tolower(frase[i]) == lettere[j]) {
				trovato = 1;
				break;
			}
		}

		if (trovato == 1) {
			res[i] = frase[i];
			trovato = 0;
		}
		else {
			if (isalpha(frase[i]) == 0) {
				res[i] = frase[i];
			}
			else {
				res[i] = '*';
			}
			
			trovato = 0;
		}
	}
	res[i] = '\0';

	return res;


}