#include<stdlib.h>


void InsMinore(int* v, int lastpos) {
	int x = v[lastpos], i;
	for (i = lastpos - 1; i >= 0 && x < v[i]; i--) {
		v[i + 1] = v[i];
	}
	v[i + 1] = x;
}

void InsertionSort(int* v, size_t v_size) {
	int i;
	for ( i = 1; i < (int)v_size; i++) {
		InsMinore(v, i);
	}
}