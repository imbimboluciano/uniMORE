#include "tree.h"
#include<stdlib.h>


bool TreeIsMirrorRec(const Node* t1,const Node* t2){
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}

	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}

	return (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) + 1) && TreeIsMirrorRec(TreeLeft(t1), TreeRight(t2)) && TreeIsMirrorRec(TreeRight(t1), TreeLeft(t2));
}

bool TreeIsMirror(const Node* t){
	return TreeIsMirrorRec(TreeLeft(t),TreeRight(t));
}


// Questa Implementazione non funziona sempre
/*
void ContaNodi(const Node* t, int** val, int* i) {
	if (TreeIsEmpty(t)) {
		return;
	}

	ContaNodi(TreeLeft(t), val, i);

	
	*val = realloc(*val, (*i + 1) * sizeof(int));
	(*val)[(*i)] = *TreeGetRootValue(t);
	(*i)++;

	ContaNodi(TreeRight(t), val, i);

}



bool TreeIsMirror(const Node* t) {

	if (TreeIsEmpty(t))	return 1;
	int h = 0;
	int* val = malloc(h * sizeof(int));
	ContaNodi(t, &val,&h);
	if (h == 1)	return 1;

	bool isMirror = 1;
	int met = h / 2;
	for (int j = 0; j < met; j++) {	
		if (val[j] != val[met + 1 + (met - j - 1)]) {
				isMirror = 0;
				break;
			}
	}
	
	free(val);
	return isMirror;
}*/