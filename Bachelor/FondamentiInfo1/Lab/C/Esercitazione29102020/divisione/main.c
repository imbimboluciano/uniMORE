int divisione(double a, double b, double* q) {
	if (b) {
		*q = a / b;
		return 1;
	}
	return 0;
}

int main(void) {

	double a = 5, b = 3;
	double div;
	double* q = &div;
	double ris = divisione(a, b, q);
	return 0;
}