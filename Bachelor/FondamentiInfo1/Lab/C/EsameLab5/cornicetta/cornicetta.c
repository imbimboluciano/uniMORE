#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void stampa_cornicetta(const char* s) {
	int l = strlen(s);
	int dim = l + 5;
	char* s1 = calloc(dim, 1);
	char* s2 = calloc(dim, 1);
	for (int i = 0; i < (dim - 1); i++) {
		s1[i] = '-';
		s2[i] = '-';
	}
	s1[0] = '/';
	s2[0] = '\\';
	s1[dim - 2] = '\\';
	s2[dim - 2] = '/';
	fprintf(stdout, "%s\n| %s |\n%s\n", s1, s, s2);
	free(s1);
	free(s2);
}