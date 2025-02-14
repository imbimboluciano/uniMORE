#include <stdio.h>

int conta_vocali_consonanti(unsigned char* src, int* dstV, int* dstC);

int main(void) {
	char src[255] = "CIAO";
	int dstV;
	int dstC;
	int ret = conta_vocali_consonanti(src, &dstV, &dstC);

	printf("Vocali=%d Consonanti=%d \n", dstV, dstC);
	return 0;
}