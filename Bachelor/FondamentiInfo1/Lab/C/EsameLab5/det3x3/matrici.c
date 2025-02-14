#include "matrici.h"

double det3x3(double* matr) {
	double somma = 0;
	double dif = 0;
	somma += matr[0] * matr[4] * matr[8];
	somma += matr[1] * matr[5] * matr[6];
	somma += matr[2] * matr[3] * matr[7];
	dif -= matr[6] * matr[4] * matr[2];
	dif -= matr[7] * matr[5] * matr[0];
	dif -= matr[8] * matr[3] * matr[1];
	return somma + dif;
}