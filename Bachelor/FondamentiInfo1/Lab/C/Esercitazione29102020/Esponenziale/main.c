double potenza(double x, int n) {
	double ris = 1;
	for (int i = 0; i < n; ++i) {
		ris = ris * x;
	}
	return ris;
}
double fattoriale(int n) {
	double fatt = 1;
	while (n > 0) {
		fatt = fatt * n;
		n--;
	}
	return fatt;
}

double exp(double x) {

	double s = 0;
	double prec = -1;
	for (int i = 0; prec != s; ++i) {
		prec = s;
		s += potenza(x,i) / fattoriale(i);
	}
	return s;
}

int main(void) {

	double x = 5;
	double ris = exp(x);
	return 0;
}