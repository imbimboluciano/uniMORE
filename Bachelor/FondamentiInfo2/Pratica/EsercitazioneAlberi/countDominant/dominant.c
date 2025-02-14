#include "tree.h"

void CountDominantRec(const Node* t, int* count){
	if (TreeIsLeaf(t)) {
		return;
	}


	if (!TreeIsEmpty(TreeLeft(t)) && !TreeIsEmpty(TreeRight(t))) {
		ElemType s = *TreeGetRootValue(TreeLeft(t));
		s += *TreeGetRootValue(TreeRight(t));
		if (ElemCompare(TreeGetRootValue(t),&s) > 0) {
			(*count)++;
		}
	}

	CountDominantRec(TreeLeft(t), count);
	CountDominantRec(TreeRight(t), count);
	
}


int CountDominant(const Node* t) {
	if (TreeIsEmpty(t))	return 0;

	int count = 0;
	CountDominantRec(t, &count);

	return count;
}