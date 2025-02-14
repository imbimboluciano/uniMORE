#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int contacifre(long long int x) {
	int n = 0;
	for (int i = 0; x != 0; i++) {
		x /= 10;
		n++;
	}
	return n;
}

char* somma_stringhe(const char* a, const char* b){
	if (a == 0 && b == 0) return 0;
	if (a == NULL || b == NULL) return NULL;

	long long int val = atoll(a);
	long long int val2 = atoll(b);
	long long int somma = val + val2;
	int n = contacifre(somma);
	char* res = calloc(n + 2, sizeof(char));
	sprintf(res, "%lld", somma);

	return res;
}
