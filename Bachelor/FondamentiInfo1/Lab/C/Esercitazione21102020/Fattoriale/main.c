unsigned int fattoriale(unsigned char val) {
	unsigned int fatt = 1;
	while (val > 0) {
		fatt = fatt * val;
		val--;
	}
	return fatt;
}

int main(void) {

	unsigned char val = 9;
	unsigned int fatt;

	fatt = fattoriale(val);

	return 0;
}