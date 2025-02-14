#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>

char* trim(const char* s) {
	if (s != NULL) {
		size_t l = strlen(s);
		char* res = calloc(l, 1);
		while (*s == ' '){
			s++;
		}
		strcpy(res,s);
		l = strlen(res);
		if (res[l - 1] == ' ') {
			res[l] = '\0';
			res = realloc(res,l);
			
		}
		return res;
	}
	return NULL;
}