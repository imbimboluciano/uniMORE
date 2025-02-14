#include<stdbool.h>
#include<stdlib.h>

extern bool is_terna_pitagorica(unsigned int a, unsigned int b, unsigned int c);

int main(void) {

	unsigned int a = 5, b = 3, c = 4;
	bool is = is_terna_pitagorica(a, b, c);
	return 0;
}
