#include "sample.h"

int main(void) {
	struct sample s = { 0,"ciao",1.35 };
	FILE* f = fopen("ciao.bin", "wb");
	int res = sample_scrivi(f, &s);
	return 0;
}