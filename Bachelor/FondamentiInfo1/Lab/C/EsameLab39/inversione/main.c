#include<stdbool.h>
extern bool inverti_case(const char* nomefilein, const char* nomefileout);

int main(void) {
	bool res = inverti_case("in1", "out.txt");
	return 0;
}