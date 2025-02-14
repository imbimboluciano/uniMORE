
double fattoriale(int n) {
	double fatt = 1;
	while (n > 0) {
		fatt = fatt * n;
		n -= 2;
	}
	return fatt;
}

double semifattoriale(char n) {
	if (n < 0) return -1;
	double sf = 1;
	if (n == 0 || n == 1) return sf;
	sf = fattoriale(n);
	return sf;
}