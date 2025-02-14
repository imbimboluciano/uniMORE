#include<stdlib.h>
size_t conta_parole(const char* s) {
	size_t dim = 0;
	int doppio = 0;
	if (s == NULL || s[0] == 0) {
		return 0;
	}

	for (size_t i = 0; s[i] != 0; i++) {

		if (s[i] == 32 && doppio == 1) {
			doppio = 0;
			dim++;
		}
		if (s[i] != 32) {
			doppio = 1;
		}
			
	 }
	return dim+doppio;
}