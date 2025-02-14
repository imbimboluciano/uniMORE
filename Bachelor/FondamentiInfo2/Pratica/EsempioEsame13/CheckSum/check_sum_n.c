#include "tree.h"
#include<stdlib.h>

void CheckSumNRec(const Node* t, int* i,int *vcurr) {
    if (TreeIsEmpty(t)) {
        return;
    }

    CheckSumNRec(TreeLeft(t), i,vcurr);

    (*i)++;
    vcurr = realloc(vcurr, (*i) * sizeof(int));
    vcurr[(*i) - 1] = *TreeGetRootValue(t);


    CheckSumNRec(TreeRight(t), i,vcurr);
}



bool CheckSumN(const Node* t, int n) {

	int* vcurr = calloc(1,sizeof(int));

    int size = 0;
    CheckSumNRec(t, &size, vcurr);

    for (int i = 0; i < size; i++) {
        for (int k = i + 1; k < size; k++) {
            if (vcurr[i] + vcurr[k] == n) {
                return true;
            }
        }
    }

    return false;
	
}