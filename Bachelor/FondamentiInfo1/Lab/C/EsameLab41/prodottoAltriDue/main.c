#include<stdlib.h>

extern int prodotto_altri_due(const int* v, size_t n);

int main(void) {
	int v[] = { 1, 12, 2, 3, 4, 5, 6 };
	int res = prodotto_altri_due(v, 7);
	return 0;
}
