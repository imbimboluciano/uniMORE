#include "stringhe.h"

int main(void) {
	char* res = center("", 2, '-');
	free(res);
	return 0;
}