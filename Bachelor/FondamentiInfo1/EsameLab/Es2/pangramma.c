#define _CRT_SECURE_NO_WARNINGS
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

static char alfabeto[] = { 'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};

bool is_pangram(const char* sentence) {
	if (sentence == NULL)	return false;
	if (strcmp(sentence, "") == 0)	return false;

	int trovato = 0;
	int* vt = calloc(21, sizeof(int));
	for (size_t i = 0; i < 21; i++) {
		for (size_t j = 0 ; sentence[j] != 0; j++) {
			if (alfabeto[i] == sentence[j] || alfabeto[i] == tolower(sentence[j])) {
				trovato = 1;
				break;
			}
		}

		if (trovato == 1) {
			vt[i] = 1;
			trovato = 0;
		}
		else {
			vt[i] = 0;
			trovato = 0;
		}
	}

	for (size_t h = 0; h < 21; h++) {
		if (vt[h] == 0) {
			free(vt);
			return false;
		}
	}
	free(vt);
	return true;


}