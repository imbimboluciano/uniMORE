#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

void SubsetKRec(int n, int k, bool* vcurr, int i, int* nsol,int cnt) { //funzione ricorsiva che implementa l'algoritmo
	if (cnt == k) { // dopo k elementi possiamo "potare"
		(*nsol)++;
		printf("{ ");
		for (int j = 0; j < i; ++j) {
			if (vcurr[j]) {
				printf("%d ", j);
			}
		}
		printf("}, ");
		return;
	}
	
	if (i == n) { //caso base i == n vuol dire che siamo arrivati ad una foglia
		return;
	}

	vcurr[i] = 0;
	SubsetKRec(n, k, vcurr, i + 1, nsol,cnt);

	vcurr[i] = 1;
	SubsetKRec(n, k, vcurr, i + 1, nsol,cnt + 1);

}

int SubsetK(int n, int k) { // funzione di appoggio

	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;
	SubsetKRec(n, k, vcurr, 0, &nsol,0);
	return nsol;
}


int main(void) {
	SubsetK(4, 2);
	return 0;
}