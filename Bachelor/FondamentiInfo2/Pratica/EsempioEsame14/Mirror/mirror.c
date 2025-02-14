#include "tree.h"

bool TreeIsMirrorRec(Node* t1, Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}

	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}

	return (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) + 1) && TreeIsMirrorRec(TreeLeft(t1),TreeRight(t2)) && TreeIsMirrorRec(TreeRight(t2), TreeLeft(t1));
}



bool TreeIsMirror(Node* t) {
	if (TreeIsEmpty(t)) {
		return true;
	}

	return TreeIsMirrorRec(TreeLeft(t), TreeRight(t));
}