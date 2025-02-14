#include<stdlib.h>

size_t lungh(const char* str) {
	size_t length = 0;;
	while (str[length] != 0) {
		length++;
	}
	return length;
}