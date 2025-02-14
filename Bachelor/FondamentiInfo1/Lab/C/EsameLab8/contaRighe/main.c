#include "righe.h"

int main(void) {
	FILE* f = fopen("file1.txt", "r");
	int r = conta_righe(f);
	return 0;
}