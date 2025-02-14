#include<stdbool.h>
extern bool is_date(const char* s);

int main(void) {
	bool res = is_date("10.07.2015");
	return 0;
}