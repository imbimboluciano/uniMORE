#include "readperson.h"


void person_read(FILE* f, struct person* pp) {

	fscanf(f, "%s %u", pp[0].name, &pp[0].age);
}