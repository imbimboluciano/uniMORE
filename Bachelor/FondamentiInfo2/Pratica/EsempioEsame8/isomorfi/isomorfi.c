#include "tree.h"

bool IsomorfiRec(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2) ) {
		return false;
	}

	return (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) + 1) && (IsomorfiRec(TreeLeft(t1), TreeLeft(t2)) || IsomorfiRec(TreeLeft(t1), TreeRight(t2))) && (IsomorfiRec(TreeRight(t1), TreeRight(t2)) || IsomorfiRec(TreeRight(t1), TreeLeft(t2)));

}



bool Isomorfi(const Node* t1, const Node* t2) {

	return IsomorfiRec(t1, t2);
}
