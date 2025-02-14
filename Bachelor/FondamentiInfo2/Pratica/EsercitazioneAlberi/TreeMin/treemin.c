#include "tree.h"

const ElemType* BstTreeMin(const Node* n) {
	if (TreeIsEmpty(n))	return NULL;
	const ElemType* min = TreeGetRootValue(n);
	n = TreeLeft(n);

	while (!TreeIsEmpty(n)) {
		if (ElemCompare(min, TreeGetRootValue(n)) >= 0) {
			min = TreeGetRootValue(n);
		}
		n = TreeLeft(n);
	}

	return min;
}

static void TreeMinRec(const Node* n, const ElemType** min,
    int* livello_max, int livello) {
    if (TreeIsEmpty(n)) {
        return;
    }

    if ((ElemCompare(*min, TreeGetRootValue(n)) > 0) ||
        (ElemCompare(*min, TreeGetRootValue(n)) == 0 && *livello_max <= livello)) {
        *min = TreeGetRootValue(n);
        *livello_max = livello;
    }

    TreeMinRec(TreeRight(n), min, livello_max, livello + 1);
    TreeMinRec(TreeLeft(n), min, livello_max, livello + 1);
   
}

const ElemType* TreeMin(const Node* n) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }

    const ElemType* min = TreeGetRootValue(n);
    int livello_max = 0;
    //TreeMaxRec(n, &max, &livello_max, 0);
    TreeMinRec(TreeLeft(n), &min, &livello_max, 1);
    TreeMinRec(TreeRight(n), &min, &livello_max, 1);
    return min;
}