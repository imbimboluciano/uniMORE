#include "complessi.h"

int main(void) {
	FILE* f = fopen("complessi.txt", "r");
	if (f == NULL) return 0;
	struct complesso comp = { 0,0 };
	int i = read_complesso(&comp, f);
	FILE* f2 = fopen("out.txt", "a");
	write_complesso(&comp, f2);
	struct complesso comp2 = { 2.5,4.6 };
	prodotto_complesso(&comp, &comp2);
	return 0;
	
}