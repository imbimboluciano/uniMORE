#include<stdlib.h>
extern int* prodotto(const int* v, size_t n);

int main(void) {
	int v[] = { 1,2,3,4,5 };
	int* res = prodotto(v, 5);
	free(res);
	return 0;
}