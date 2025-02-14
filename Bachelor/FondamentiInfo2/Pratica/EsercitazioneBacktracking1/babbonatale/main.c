#include<stdlib.h>

extern void BabboNatale(const int* pacchi, size_t pacchi_size, int p);

int main(void) {

	int pacchi[] = { 10,11,1,3,3 };
	BabboNatale(pacchi, 5, 20);
	return 0;
}