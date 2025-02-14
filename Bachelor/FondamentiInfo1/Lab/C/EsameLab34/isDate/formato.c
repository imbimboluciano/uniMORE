#include<stdbool.h>
#include<string.h>

int check_cifra(char x) {
	int c = 0;
	if (x >= 48 && x <= 57) c = 1;
	return c;
}

bool is_date(const char* s) {
	if (strlen(s) != 10) return false;
	for (int i = 0; s[i] != 0; i++) {
		if (i == 2 || i == 5) {
			if (s[i] != '/') return false;
		}
		else {
			if (check_cifra(s[i]) == 0) return false;
		}
	}
	return true;
}