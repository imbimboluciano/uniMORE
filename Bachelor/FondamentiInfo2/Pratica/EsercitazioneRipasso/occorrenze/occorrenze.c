#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int occorrenze(char* str, char c) {
	int parola = 0;
	int occ = 0;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i]>= 'a' && str[i]<= 'z') {
			parola = 1;
			if (str[i] == c) {
				occ++;
			}
		}
		else if (str[i] == ' ') {
			if (parola == 1) {
				parola = 0;
			}
		}
	}

	return occ;
}


int main(int argc, char* argv[]) {
	if (argc != 3)  {
			fprintf(stderr, "%s", "Il numero di parametri non è corretto. Sintassi del programma: occorenze <s> < c>");
			return 1;
	}

	int c = occorrenze(argv[1], *argv[argc - 1]);
	fprintf(stdout, "%d", c);
	return 0;


}