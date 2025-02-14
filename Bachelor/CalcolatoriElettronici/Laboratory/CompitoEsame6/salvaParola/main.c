#include <stdio.h>

int salvaparolaspiazzamento(char* s, char* d, unsigned char* parola1);

int main(void) {

	char s[255] = "ciao mamma";
	char d[255];
	char parola1[50] = "ciao";


	salvaparolaspiazzamento(s, d, parola1);
	printf("%s\n", s);
	printf("%s", d);

	return 0;
}