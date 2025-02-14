#include "path_split.h"

int main(void) {
	char* path = NULL;
	char* filename = NULL;
	path_split("esercizi\\",&path,&filename);
	return 0;
}