#include "counttenenager.h"

int main(void) {
	FILE* f = fopen("people1.txt", "r");
	if (f == NULL) return 0;
	int t = count_teenagers(f);
	return 0;
}