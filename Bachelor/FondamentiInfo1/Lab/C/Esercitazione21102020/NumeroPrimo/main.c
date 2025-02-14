int primo(unsigned int val) {
	int divisore = 1, conta_divisori = 0;
	while (conta_divisori < 3 && divisore <= (val / 2)) {
		if ((val % divisore) == 0) conta_divisori++;
		divisore++;
	}
	if (conta_divisori == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {

	unsigned int val = 8;
	int pri;

	pri = primo(val);
}