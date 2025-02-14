#include<stdlib.h>
extern int* rimuovi_multipli(const int* v, size_t size, size_t* newsize);

int main(void) {
	int v[] = { 2,3,4,5,6 };
	size_t newsize;
	int* res = rimuovi_multipli(v, 5, &newsize);
	return 0;
}