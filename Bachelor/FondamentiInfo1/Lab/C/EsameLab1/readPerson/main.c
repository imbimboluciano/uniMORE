#include "readperson.h"


int main(void) {

	FILE* f = fopen("person1.txt", "r");
	if (f == NULL) return 0;
	struct person p = { NULL,0 };
	person_read(f, &p);
	return 0;
}