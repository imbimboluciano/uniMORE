#include<stdio.h>

int assitoa(int src, int sgn, char* stringa);

int main(void) {

	char src[255];
	int ret;
	ret = assitoa(123, 0, src);

	printf("%s", src);

	return 0;
}