#include<stdbool.h>
#include<string.h>

bool IsPalindromoRec(const char* str,int start,int len) {
	if (len <= 1) return true;
	if (str[start] == str[start + len - 1] && IsPalindromoRec(str, start + 1, len - 2)) {
		return true;
	}
	else {
		return false;
	}
}


bool IsPalindromo(const char* str) {
	if (str == NULL) {
		return false;
	}
	if (!strcmp(str, "")) {
		return true;
	}

	int len = strlen(str);
	return IsPalindromoRec(str, 0, len);

}