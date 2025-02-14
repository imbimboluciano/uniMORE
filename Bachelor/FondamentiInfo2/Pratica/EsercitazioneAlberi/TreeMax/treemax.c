#include "tree.h"

const ElemType* BstTreeMax(const Node* n) {
	if (TreeIsEmpty(n))	return NULL;
	const ElemType* max = TreeGetRootValue(n);
	n = TreeRight(n);

	while (!TreeIsEmpty(n)) {
		if (ElemCompare(max, TreeGetRootValue(n)) < 0) {
			max = TreeGetRootValue(n);
		}
		n = TreeRight(n);
	}

	return max;

}

static void TreeMaxRec(const Node* n, const ElemType** max,
    int* livello_max, int livello) {
    if (TreeIsEmpty(n)) {
        return;
    }

    if ((ElemCompare(*max, TreeGetRootValue(n)) < 0) ||
        (ElemCompare(*max, TreeGetRootValue(n)) == 0 && *livello_max > livello)) {
        *max = TreeGetRootValue(n);
        *livello_max = livello;
    }

    TreeMaxRec(TreeLeft(n), max, livello_max, livello + 1);
    TreeMaxRec(TreeRight(n), max, livello_max, livello + 1);
}

const ElemType* TreeMax(const Node* n) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }

    const ElemType* max = TreeGetRootValue(n);
    int livello_max = 0;
    //TreeMaxRec(n, &max, &livello_max, 0);
    TreeMaxRec(TreeLeft(n), &max, &livello_max, 1);
    TreeMaxRec(TreeRight(n), &max, &livello_max, 1);
    return max;
}
