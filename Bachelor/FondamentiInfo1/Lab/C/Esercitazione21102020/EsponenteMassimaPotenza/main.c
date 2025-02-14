char max_pot10(unsigned int val) {
	
	int val_pot10 = 1;
	int esp = 0;
	while (!((val_pot10 <= val) && (val <= (val_pot10*10)))){
		if (esp == 0) {
			esp++;
		}
		else {
			val_pot10 = val_pot10 * 10;
			esp++;
		}
	}

	if (esp == 0) {
		return -1;
	}
	else {
		return esp-1;
	}
}

int main(void) {

	int max_esp;
	unsigned int val;
	val = 123456;

	max_esp = max_pot10(val);

	return 0;
}