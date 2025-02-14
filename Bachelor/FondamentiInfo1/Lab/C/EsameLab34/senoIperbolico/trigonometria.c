double fatt(int x) {
	double f = 1;
	while (x > 0) {
		f *= x;
		x--;
	}
	return f;
}

double pot(double x, int n) {
	double p = 1;
	while (n > 0) {
		p *= x;
		n--;
	}
	return p;
}


double seno_iperbolico(double x) {
	double senoi = 0, valPre = 1;
	for (int i = 0; valPre != senoi; i++) {
		valPre = senoi;
		senoi += (1 / fatt((2 * i) + 1)) * pot(x, (2 * i) + 1);
	}

	return senoi;
}
