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

unsigned int prossimo_numero_primo(unsigned int x) {
	int i = x + 1;
	while (!primo(i)) {
		i++;
	}
	return i;
}

