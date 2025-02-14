#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdlib.h>


void ReverseStringRec(const char* str, int len,char* res,int inizio) {
	if (len >= 1) {
		res[inizio] = str [len - 1];
		ReverseStringRec(str, len - 1, res,inizio + 1);
	}

	return;
}



char* ReverseString(const char* str) {
	if (str == NULL) {
		return NULL;
	}
	char* res = calloc(strlen(str) + 1, sizeof(char));
	ReverseStringRec(str, strlen(str), res,0);
	return res;

}
