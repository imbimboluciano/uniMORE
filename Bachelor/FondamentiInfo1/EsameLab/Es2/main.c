#include<stdbool.h>

extern bool is_pangram(const char* sentence);

int main(void) {


	bool res = is_pangram("Qualche vago ione tipo zolfo, bromo, sodio");
	return 0;
}
