#include "angoli.h"

int main(void) {

	struct angolo a =  { 230,47,12 };
	struct angolo b = { 45,23,4 };
	struct angolo som = somma_angoli(a, b);
	return 0;
}