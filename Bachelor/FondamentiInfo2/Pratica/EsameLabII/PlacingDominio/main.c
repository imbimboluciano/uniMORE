#include "domino.h"

int main(void) {

	Tessera t[] = { {.val1 = 5, .val2 = 3 }, {.val1 = 5, .val2 = 6 }, {.val1 = 5, .val2 = 4 }, {.val1 = 6, .val2 = 2 } };
	size_t i = 0;
	Placing* res = Domino(t, 4, &i);
	return 0;
}