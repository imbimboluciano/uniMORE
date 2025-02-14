#include <stdio.h>

int divisione_array(int* src, int divisore, int lunghezza, int* resto);

int main()
{
	int v[3] = { 3,3,3 };
	int r[3];
	int c = divisione_array(v, 3, 3, r);
	printf(" %d %d %d ", v[0], v[1], v[2]);
	printf(" %d %d %d ", r[0], r[1], r[2]);
	printf("%d", c);
	return 0;
}