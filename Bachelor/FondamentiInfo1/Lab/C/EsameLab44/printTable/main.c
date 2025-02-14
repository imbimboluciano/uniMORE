#include<stdint.h>

extern void print_table(char** colnames, uint8_t ncols, uint8_t nrows);

int main(void) {

	char* colnames[] = { "cioa","ciehie","iic","dhich" };
	print_table(colnames, 4, 2);
	return 0;
}