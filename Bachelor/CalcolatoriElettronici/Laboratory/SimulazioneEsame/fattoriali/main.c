#include<stdio.h>

int fattoriali(int* src, int* dst, int lunghezza);

int main(void) {

	int src[3] = { 1,3,0 };
	int dst[3];
	int ret;

	ret = fattoriali(src, dst, 3);
	printf("%d %d %d\n", dst[0], dst[1], dst[2]);
	ret = fattoriali(src, dst, 3);
	printf("%d %d %d\n", dst[0], dst[1], dst[2]);



	return 0;
}