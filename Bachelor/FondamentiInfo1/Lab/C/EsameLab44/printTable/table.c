#define _CRT_SECURE_NO_WARNINGS
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

void print_table(char** colnames, uint8_t ncols, uint8_t nrows) {
	if (ncols != 0 || nrows != 0) {
		fprintf(stdout, "|");
		for (int i = 0; i < ncols; i++)
		{
			fprintf(stdout, "%-9s|", colnames[i]);
		}
		fprintf(stdout, "\n");
		size_t dim = ncols * 10;
		char* s1 = calloc(dim + 1, 1);
		for (size_t i = 0; i < dim; i++)
		{
			if (i % 10 == 0)
			{
				s1[i] = '+';
			}
			else
			{
				s1[i] = '-';
			}
		}
		char* s2 = calloc(dim + 1, 1);
		for (size_t i = 0; i < dim; i++)
		{
			if (i % 10 == 0)
			{
				s2[i] = '|';
			}
			else
			{
				s2[i] = ' ';
			}
		}
		for (int i = 0; i < nrows; i++)
		{
			fprintf(stdout, "%s+\n%s|\n", s1, s2);
		}
		fprintf(stdout, "%s+\n", s1);
		free(s1);
		free(s2);
	}


}