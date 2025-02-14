#include<stdlib.h>

extern unsigned int irpef(unsigned int stipendio, unsigned int* scaglioni, unsigned int* aliquote, size_t n);

int main(void) {

	unsigned int scaglioni[] = { 0, 15000, 28000, 55000, 75000 };
	unsigned int aliquote[] = { 23, 27, 38, 41, 43 };
	unsigned int irp = irpef(25000, scaglioni, aliquote, 5);
	return 0;
}