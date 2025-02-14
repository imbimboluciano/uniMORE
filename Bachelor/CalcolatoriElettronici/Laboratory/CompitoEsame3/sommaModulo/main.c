#include<stdio.h>

int somma_modulo(int* src, int lunghezza, int* dst, int divisore);

int main(void) {
	
	int src[10] = { 1,2,3,4,57,-1,-2,-3,-46,-55 };
	int dst[10];
	int ret = somma_modulo(src, 10, dst, 5);
	ret = somma_modulo(src, 10, dst, 5);
	printf("Somma=%d ", ret);
	for (int i = 0; i < 10; i++) {
		printf("%d ", dst[i]);
	}
	return 0;
}