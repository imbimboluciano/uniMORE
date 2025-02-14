#include<math.h>

double fatt(int x) {
	double f = 1;
	while (x > 0) {
		f = f * x;
		x--;
	}
	return f;
}

double calcola_seno(double x) {
	double sen = 0.0;
	for (int n = 0; n < 20; n++) {
		sen += pow(-1, n) / fatt(2 * n + 1) * pow(x, 2 * n + 1);
	}
	return sen;
}