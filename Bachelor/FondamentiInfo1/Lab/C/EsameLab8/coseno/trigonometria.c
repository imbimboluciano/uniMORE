double fatt(int x) {
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

double coseno(double x) {
	double coseno = 0, valPre = 1;
	for (int i = 0; valPre != coseno; i++) {
		valPre = coseno;
		coseno += (potenza(-1, i) / fatt(2 * i)) * potenza(x, 2 * i);
	}
	return coseno;
}