#include "stringhe.h"

char* title(const char* str) {
	if (str == NULL) return NULL;
	size_t l = strlen(str);
	char* res = calloc(l + 1,sizeof(char));
	size_t i = 0;
	int parola = 0;
	int first = 0;
	for (i = 0; str[i] != 0; i++) {
		if (isalpha(str[i])) {
			if (first == 0) {
				res[i] = toupper(str[i]);
				first = 1;
			}
			else {
				res[i] = str[i];
			}
			
			parola = 1;
		}
		else if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'){
			if (parola == 1){
				parola = 0;
				first = 0;
			}
			res[i] = str[i];

		}
		else {
			res[i] = str[i];
		}
	}
	res[i] = '\0';
	return res;
}