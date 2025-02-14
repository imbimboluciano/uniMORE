#include "nonogram.h"


int main(void) {
	struct nonogram n = { 0,NULL };
	bool res = nonogram_load(&n, "nonogram1.txt");
	return 0;
}