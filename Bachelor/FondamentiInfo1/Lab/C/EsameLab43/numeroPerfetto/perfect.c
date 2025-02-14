#include<stdbool.h>
#include<stdint.h>

bool is_perfect(uint32_t n) {

	unsigned int somma = 0;
	unsigned int i = 1;
	while (i < n) {
		if (n % i == 0) {
			somma += i;
		}
		i++;
	}

	if (somma == n)	return true;
	else return false;
}
