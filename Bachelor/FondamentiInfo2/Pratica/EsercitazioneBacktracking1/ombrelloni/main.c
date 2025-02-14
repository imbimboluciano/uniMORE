#include<time.h>
#include<stdio.h>

extern int Ombrelloni(int k, int n);
extern int OmbrelloniPruning(int k, int n);

int main(void) {

	int tick = clock();   // tempo passato dall'inizio del programma
	int sol = Ombrelloni(3, 10);
	int tock = clock();
	double elapsed = (tock - tick)/(double) CLOCKS_PER_SEC; // tempo funzione
	printf("Elapsed NO Pruning: %f\n", elapsed);

	tick = clock();   // tempo passato dall'inizio del programma
	sol = OmbrelloniPruning(3, 10);
	tock = clock();
	elapsed = (tock - tick) / (double)CLOCKS_PER_SEC; // tempo funzione
	printf("Elapsed Pruning: %f\n", elapsed);

	return 0;
}