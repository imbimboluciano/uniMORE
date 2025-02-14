#include "tree.h"


Node* BstInsertRec(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n)) {
		return  TreeCreateRoot(e, NULL, NULL);
	}
	else if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
		n->left = BstInsertRec(e, TreeLeft(n));
	}
	else {
		n->right = BstInsertRec(e, TreeRight(n));
	}

	return n;
}

void Tree2BstRec(const Node* t, Node** res) {
	if (TreeIsEmpty(t)) {
		return;
	}

	Tree2BstRec(TreeLeft(t),res);

	 *res = BstInsertRec(TreeGetRootValue(t),*res);

	Tree2BstRec(TreeRight(t),res);

}


Node* Tree2Bst(const Node* t) {
	if (TreeIsEmpty(t)) {
		return NULL;
	}
	Node* res = TreeCreateEmpty();
	Tree2BstRec(t, &res);

	return res;
}