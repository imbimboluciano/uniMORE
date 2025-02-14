
double fatt(double x) {
	double fatt = 1;
	while (x > 0) {
		fatt *= x;
		x--;
	}
	return fatt;
}

double potenza(double x, int n) {
	double p = 1;
	for (int i = 0; i < n; i++) {
		p *= x;
	}
	return p;
}

double seno(double x) {
	double seno = 0, valPre = 1;
	for (int i = 0; valPre != seno; i++) {
		valPre = seno;
		seno += (potenza(-1, i) / fatt((2*i)+1)) * potenza(x, (2 * i) + 1);
	}
	return seno;
}