
unsigned int conta_spazi(const char* s) {
	unsigned int spazi = 0;
	int i = 0;
	while (s[i] != 0) {
		if (s[i] == 32) spazi++;
		i++;
	}
	return spazi;
}
