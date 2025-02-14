#include<stdbool.h>
#include<stdlib.h>

bool is_ugly(unsigned int num) {

	unsigned int* fprimi = NULL;
	size_t j = 0;
	size_t i = 2;
	while(1){
		if (num == 1) break;
		if (num % i == 0) {
			j++;
			fprimi = realloc(fprimi, j * sizeof(unsigned int));
			fprimi[j - 1] = i;
			num /= i;
		}
		else {
			i++;
		}
	}

	int trovato = 1;
	for (size_t i = 0; i < j; i++) {
		if (fprimi[i] != 2 && fprimi[i] != 3 && fprimi[i] != 5) {
			trovato = 0;
			break;
		}
	}
	free(fprimi);
	if(trovato == 1) return true;
	else   return false;


}
