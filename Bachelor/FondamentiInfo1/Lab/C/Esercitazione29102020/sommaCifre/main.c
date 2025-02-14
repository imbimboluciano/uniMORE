unsigned int somma_cifre(unsigned int x) {

	unsigned int tot = 0;
	while (x != 0) {
		tot += x % 10;
		x = x / 10;
	}
	return tot;
}

int main(void) {

	unsigned int val = 54, ris;
	ris = somma_cifre(val);
	return 0;
}