#include<stdlib.h>
#include<stdbool.h>

bool is_arithmetic(const int* v, size_t n) {
	if (n >= 2) {
		if (n == 2)	return true;
		int diff = v[0] - v[1];
		for (size_t i = 1; i < n - 1; i++) {
			if (v[i] - v[i + 1] != diff) {
				return false;
			}
		}

		return true;


	}
	return false;

}