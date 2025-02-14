#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int moltiplicazione(int a, int b) {
	return a * b;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		
		fprintf(stderr, "%s\"mul <a> <b>\"", "Il numero di parametri non è corretto.Sintassi del programma : ");
		return 1;
	}

	int prod = moltiplicazione(atoi(argv[1]), atoi(argv[argc - 1]));
	fprintf(stdout, "%d", prod);
	return 0;

}