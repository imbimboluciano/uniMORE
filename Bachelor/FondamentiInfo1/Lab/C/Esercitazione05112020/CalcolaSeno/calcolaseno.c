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

double calcola_seno(double x) {
	double seno = 0, valPre = 1;
	for (int i = 0; valPre != seno ; ++i) {
		valPre = seno;
		seno += (potenza(-1, i) / fattoriale((2 * i) + 1)) * potenza(x, (2 * i) + 1);
	}
	return seno;
}