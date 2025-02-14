#include "counttenenager.h"

unsigned int count_teenagers(FILE* f) {
	int t = 0;
	int i = 0;
	fscanf(f, "%i\n",&i);
	struct person people = { NULL,0 };
	for (int j = 0; j < i; j++) {
		fscanf(f, "%s %u\n", &people.name, &people.age);
		if (people.age > 13 && people.age < 19) {
			t++;
		}
	}
	return t;
}