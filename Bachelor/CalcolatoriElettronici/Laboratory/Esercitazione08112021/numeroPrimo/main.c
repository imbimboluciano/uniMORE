#include<stdio.h>

int numeroprimo(unsigned int n);

int main(void) {

	int i = numeroprimo(6);

	if (i == 1) {
		printf("%s", "Numero primo");
	}
	else {
		printf("%s", "Numero non primo");
	}
	return 0;
}