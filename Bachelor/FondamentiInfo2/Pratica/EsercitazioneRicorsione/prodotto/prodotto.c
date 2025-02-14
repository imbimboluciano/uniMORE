
int Prodotto(int a, int b) {

	if (a < 0 || b < 0) return -1;

	if (b == 0) {
		return 0;
	}
	return a + Prodotto(a, b - 1);
}