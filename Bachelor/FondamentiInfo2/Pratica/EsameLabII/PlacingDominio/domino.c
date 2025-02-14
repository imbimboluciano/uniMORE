#include "domino.h"
#include<stdlib.h>
#include<string.h>


void DominoRec(const Tessera* t, size_t t_size, size_t* ret_size, size_t i, int* vcurr, Placing* sol, int* max, Placing* curr) {

	if (i == t_size) {
		int n_size = 0;
		bool flap = false;
		for (size_t j = 0; j < i; j++) {
			if (vcurr[j] == 1) {
				if (t[j].val2 == t[j + 1].val1) {
					n_size++;
					curr[n_size - 1].indice = j;
					curr[n_size - 1].flipped = flap;
					curr[n_size].indice = j;
					curr[n_size].flipped = flap;

				}
				else if(t[j].val2 == t[j + 1].val1){

				}
			}
			
		}
		if (n_size > max) {
			max = n_size;
			memcpy(curr, sol,max);
		}

		return;
	}

	vcurr[i] = 0;
	DominoRec(t, t_size, ret_size, i + 1, vcurr, sol,max,curr);

	vcurr[i] = 1;
	DominoRec(t, t_size, ret_size, i + 1, vcurr, sol, max,curr);
}



Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size) {

	int* vcurr = calloc(t_size, sizeof(int));
	Placing* sol = calloc(*ret_size, sizeof(Placing));
	Placing* curr = calloc(*ret_size, sizeof(Placing));
	DominoRec(t, t_size, ret_size, 0, vcurr,sol,0,curr);

	return sol;
 }