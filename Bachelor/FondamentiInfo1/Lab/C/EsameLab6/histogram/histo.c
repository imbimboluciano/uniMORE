#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void histogram(const char* values, size_t n) {
	if (values != NULL || n != 0) {
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < (size_t)values[i]; j++) {
				fprintf(stdout, "%c", '*');
			}
			fprintf(stdout, "\n");
		}
	}
}