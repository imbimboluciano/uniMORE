
double fatt(unsigned int n) {
	double fatt = 1;
	while (1) {
		if (n == 0) break;
		fatt *= n;
		n--;
	}
	return fatt;
}

double binomiale(unsigned int n, unsigned int k) {
	if (n == 0 || k > n) return -1;
	double bin; 
	bin = fatt(n) / (fatt(k) * fatt(n - k));
	return bin;
}