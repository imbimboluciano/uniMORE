#include "tree.h"
#include<float.h>

int ContaNodi(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	
	return 1 + ContaNodi(TreeLeft(t)) + ContaNodi(TreeRight(t));
}


void MedianoAdd(const Node* t, int n, double* med, int *count) {
	if (TreeIsEmpty(t)) {
		return;
	}
	
	MedianoAdd(TreeLeft(t), n, med, count);
	(*count)++;
	if (*count == n || *count == n + 1) {
		*med += (double)*TreeGetRootValue(t);
	}
	MedianoAdd(TreeRight(t), n, med, count);

}
void MedianoRec(const Node* t, int n, double* med, int* count) {
	if (TreeIsEmpty(t)) {
		return;
	}

	MedianoRec(TreeLeft(t), n, med, count);
	if (*count == n ) {
		*med += (double)*TreeGetRootValue(t);
	}
	(*count)++;
	MedianoRec(TreeRight(t), n, med, count);

}



double Mediano(const Node* t) {

	if (TreeIsEmpty(t))	return DBL_MAX;
	int Nnodi = ContaNodi(t);
	double med = 0;
	int count = 0;
	if (Nnodi % 2 == 0) {
		MedianoAdd(t, Nnodi / 2, &med, &count);
		med = med/ 2;
	}
	else {
		MedianoRec(t, Nnodi / 2, &med, &count);
	}

	return med;
}