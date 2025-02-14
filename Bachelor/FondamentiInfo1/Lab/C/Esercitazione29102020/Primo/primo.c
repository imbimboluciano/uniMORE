int primo(unsigned int val) {

	if (val < 2) {
		return 0;
	}
	for (unsigned int i = 2; i < val; ++i) {
		if (val % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(void) {

	int x;

	x = primo(39);
	x = primo(40);
	x = primo(97);

	return 0;
}