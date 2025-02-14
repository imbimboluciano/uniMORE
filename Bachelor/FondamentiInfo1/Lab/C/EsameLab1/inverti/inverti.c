#include<math.h>
int contacifre(unsigned int x) {
	int n = 0;
	for (int i = 0; x != 0; i++) {
		x /= 10;
		n++;
	}
	return n;
}

unsigned int inverti(unsigned int i) {
	int cifre = contacifre(i);
	unsigned int  res = 0;
	for (int j= cifre - 1; j >=0; j--) {
		res += (i % 10) * pow(10, j);
		i = i / 10;
	}
	return res;
}