#include "array.h"

int main(void) {
	double arr[] = {2.5,4.3,6.7};
	size_t n = 3;
	array_remove(arr, &n, 2);
	return 0;
}