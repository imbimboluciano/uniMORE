#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char* parola_piu_lunga(const char* sz){
	size_t  c = 0;
	size_t j = 0;
	size_t max = 0;
	char parola = 0;
	char* tmp = NULL;
	char* res = NULL;
	for (size_t i = 0; i <= strlen(sz); i++){
		if (sz[i] != ' ' && sz[i] != '\n' && sz[i] != '\0' && sz[i] != '\t') {
			c++;
			tmp = realloc(tmp, c * sizeof(char));
			tmp[c - 1] = sz[i];
			parola = 1;
			
		}
		else{
			if (parola == 1){
				c++;
				tmp = realloc(tmp, c * sizeof(char));
				tmp[c - 1] = '\0';
				if (j == 0) {
					j++;
					max = c;
					res = realloc(res, max * sizeof(char));
					strcpy(res, tmp);

				}
				else if (c > max) {
					max = c;
					res = realloc(res, max * sizeof(char));
					strcpy(res, tmp);
				}
				parola = 0;
				c = 0;
			}
		}
	}
	free(tmp);
	return res;
}