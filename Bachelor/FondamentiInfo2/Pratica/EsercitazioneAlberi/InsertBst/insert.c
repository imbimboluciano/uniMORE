#include "tree.h"

Node* BstInsert(const ElemType* e, Node* n) {

	Node* l = n;

	if (TreeIsEmpty(n)) return l = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
	
	while (!TreeIsEmpty(n)){
		if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
			if (TreeIsEmpty(TreeLeft(n))) {
				n->left = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
				n = TreeLeft(n);
			}
			n = TreeLeft(n);
		}
		else if (ElemCompare(e, TreeGetRootValue(n)) > 0) {
			if (TreeIsEmpty(TreeRight(n))) {
				n->right = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
				n = TreeRight(n);
			}
			n = TreeRight(n);
		}
	}
	
	return l;
}


Node* BstInsertRec(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n)) {
		return  TreeCreateRoot(e, NULL, NULL);
	}
	else if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
		n->left = BstInsertRec(e, TreeLeft(n));
	}
	else{
		n->right = BstInsertRec(e, TreeRight(n));
	}

	return n;
}