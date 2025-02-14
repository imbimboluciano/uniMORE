#include<stdlib.h>

extern size_t conta_parole(const char* s);

int main(void) {
	char s[] = "Ciao Mamma guarda come programmo";
	size_t parole = conta_parole(s);
	return 0;
}