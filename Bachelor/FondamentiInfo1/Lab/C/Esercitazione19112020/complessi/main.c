#include "complessi.h"

int main(void) {
	struct complesso a = { 3.0,4.0 };
	struct complesso b = { 2.0,5.0 };
	prodotto_complesso(&a, &b);
	return 0;
	
}