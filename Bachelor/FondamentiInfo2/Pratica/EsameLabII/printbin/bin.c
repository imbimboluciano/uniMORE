#include<stdlib.h>
#include<string.h>
#include<stdio.h>


void bin(int n,int* temp,int *i) {
	if (n == 0) {
		return;
	}

	if (n % 2 == 0) {
		temp[*i] = 0;
		(*i)++;
		bin(n / 2, temp, i);
	}
	else {
		temp[*i] = 1;
		(*i)++;
		bin(n / 2, temp, i);
	}
}


int main(int argv, char* argc[]) {
	if (argv != 2) {
		return 1;
	}


	int n = atoi(argc[1]);
	if (n < 0) {
		return 1;
	}
	if (n == 0) {
		fprintf(stdout, "%d", 0);
	}

	int* temp = calloc(n, sizeof(int));
	int i = 0;
	bin(n, temp, &i);
	for (int k = i - 1 ; k >= 0; k--) {
		fprintf(stdout, "%d", temp[k]);
	}
	return 0;





}