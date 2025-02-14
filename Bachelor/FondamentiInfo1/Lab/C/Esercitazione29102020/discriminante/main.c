double discriminante(double a, double b, double c) {
	double dis;
	dis = (b * b) - (4 * a * c);
	return dis;
}

int main(void) {

	double a = 5, b = 7, c = 8;
	double ris = discriminante(a, b, c);
	return 0;
}