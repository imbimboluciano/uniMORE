char massimo(char x, char y) {
	if (x == y) {
		return x;
	}
	else {
		if (x < y) {
			return y;
		}
	}
	return x;
}

int main(void) {
	char x, y, z;

	x = 6;
	y = -3;
	z = massimo(x, y);
	return 0;
}