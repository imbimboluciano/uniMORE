#include<stdlib.h>

unsigned int irpef(unsigned int stipendio, unsigned int* scaglioni, unsigned int* aliquote, size_t n) {
	size_t i;
	for ( i = 0; i < n; i++) {
		if (i == 0) {
			if (stipendio < scaglioni[i + 1]) {
				i++;
				break;
			}
		}
		else if (i == n - 1) {
			if (stipendio > scaglioni[i]) {
				i++;
				break;
			}
		}
		else {
			if (stipendio > scaglioni[i]  &&  stipendio < scaglioni[i + 1]) {
				i++;
				break;
				
			}
		}
	}
	unsigned int tasse = 0;
	for (size_t j = 0; j < i; j++) {
		if (j == i - 1) {
			tasse += (stipendio - scaglioni[j]) * aliquote[j] / 100;
		}
		else {
			tasse += (scaglioni[j + 1] - scaglioni[j]) * aliquote[j] / 100;
		}
		
	}

	return  tasse;

}