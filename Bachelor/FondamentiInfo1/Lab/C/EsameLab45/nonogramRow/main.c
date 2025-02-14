#include<stdlib.h>
#include<stdint.h>


extern uint8_t* nonogram_row(const char* s, size_t* n);

int main(void) {
	size_t n = 0;
	uint8_t * res = nonogram_row("", &n);
	return 0;
}