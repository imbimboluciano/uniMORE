#include<string.h>

char* cerca_primo(char* s, const char* list) {
	int check = 0;
	int check2 = 0;
	for(size_t j = 0;s[j]!=0;j++){
		if (s[j] != ' ') check = 1;
	}
	for (size_t h = 0; list[h] != 0; h++) {
		if (list[h] != ' ') check2 = 1;
	}
	if (check == 0 || check2 == 0) return 0;
	char* trovato = (1,1);
	for (size_t i = 0; list[i] != 0; i++) {
		trovato = strchr(s, list[i]);
	}
	return trovato;
}