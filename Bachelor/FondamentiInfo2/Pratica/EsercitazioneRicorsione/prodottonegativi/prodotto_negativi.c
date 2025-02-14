

int ProdottoNegativi(int a, int b) {

	if (b == 0) {
		return 0;
	}
	if (b > 0) {
		return a + ProdottoNegativi(a, b - 1);
	}
	else {
		return (-a) + ProdottoNegativi(a, b + 1);
	}
}