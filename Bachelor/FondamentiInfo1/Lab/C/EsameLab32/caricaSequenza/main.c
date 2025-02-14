#include "sequenza.h"

int main(void) {
	struct seq s = { 0,NULL };
	bool res = seq_load("seq1.bin",&s);
	return 0;
}