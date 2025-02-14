#include<stdbool.h>
#include<stdlib.h>

bool is_terna_pitagorica(unsigned int a, unsigned int b, unsigned int c) {
	unsigned int aQ = a * a, bQ = b * b, cQ = c * c;
	if (aQ + bQ == cQ) {
		return true;
	}
	else if(aQ + cQ == bQ){
		return true;
	}
	else if (cQ + bQ == aQ) {
		return true;
	}

	return false;
}