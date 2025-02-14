#include "tree.h"

bool EquivalentiRec(const Node* t1 ,const Node* t2) {
	 
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}

	if (TreeIsLeaf(t1) && TreeIsLeaf(t2)) {
		if (((*TreeGetRootValue(t1) % *TreeGetRootValue(t2)) == 0 )   || ((*TreeGetRootValue(t2) % *TreeGetRootValue(t1)) == 0)) {
			return true;
		}
		else {
			return false;
		}
	}

	if (TreeIsLeaf(t1) || TreeIsLeaf(t2)) {
		return false;
	}

	return (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) + 1) && EquivalentiRec(TreeLeft(t1), TreeLeft(t2)) && EquivalentiRec(TreeRight(t1), TreeRight(t2));
}




bool Equivalenti(const Node* t1, const Node* t2) {

	return EquivalentiRec(t1, t2);

 }
