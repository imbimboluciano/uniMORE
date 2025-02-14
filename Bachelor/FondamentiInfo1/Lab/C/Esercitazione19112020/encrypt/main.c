#include<stdlib.h>
extern void encrypt(char* s, unsigned int n);

int main(void) {
	unsigned int n = 10;
	char s[] = malloc(n * sizeof(char));
	encrypt(s, n);
	return 0;
}