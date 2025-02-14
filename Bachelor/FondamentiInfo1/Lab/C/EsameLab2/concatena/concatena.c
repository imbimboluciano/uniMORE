#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdlib.h>


char* concatena(const char* s1, const char* s2) {
	int ls1 = strlen(s1);
	int ls2 = strlen(s2);
	char* s = calloc((ls1 + ls2),sizeof(char));
	s = strcat(s, s1);
	s = strcat(s, s2);
	return s;
}