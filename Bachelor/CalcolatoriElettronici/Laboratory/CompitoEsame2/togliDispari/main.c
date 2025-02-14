#include<stdio.h>

int togli_dispari(unsigned char* src, int lunghezza);

int main(void) {

	unsigned char src[6] = { 2,3,4,4,5,8 };
	int ret = togli_dispari(src, 6);
	 ret = togli_dispari(src, 6);

	printf("%d %d %d %d %d %d", src[0], src[1], src[2], src[3], src[4], src[5]);

	return 0;
}