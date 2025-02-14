#include<stdbool.h>
extern bool is_terna_pitagorica(unsigned int v[3]);

int main(void) {
	unsigned int v[3] = { 1,2,3 };
	bool res = is_terna_pitagorica(v);
	return 0;
}