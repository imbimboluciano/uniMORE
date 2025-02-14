

int PotenzaRec(int a, int b) {
	if (b == 0) {
		return 1;
	}
	return a * PotenzaRec(a, b - 1);
}


int Potenza(int a, int b) {
	if (b < 0)	return 0;

	return PotenzaRec(a, b);
}