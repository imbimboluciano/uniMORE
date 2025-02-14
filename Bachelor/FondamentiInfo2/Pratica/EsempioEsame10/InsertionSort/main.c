#include<stdlib.h>

extern void InsertionSort(int* v, size_t v_size);

int main(void) {

	int v[] = { 4,7,2,10,3 };
	InsertionSort(v, 5);

	return 0;
}