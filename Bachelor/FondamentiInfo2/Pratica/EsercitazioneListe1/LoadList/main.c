#include "list.h"

extern Item* ListLoad(const char* filename);

int main(void) {

	Item* res = ListLoad("data_02.txt");
	return 0;
}