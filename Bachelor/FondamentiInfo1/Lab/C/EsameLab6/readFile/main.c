#include "read_file.h"

int main(void) {
	size_t i = 0;
	byte* res = read_file("aip.txt", &i);
	free(res);
	return 0;
}