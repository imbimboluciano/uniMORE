#include "tree.h"

extern Node* DeleteBstNode(Node* n, const ElemType* key);

Node* BstInsertRec(const ElemType* e, Node* n) {
    if (TreeIsEmpty(n)) {
        return TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
    }

    if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
        // Va a sinistra
        n->left = BstInsertRec(e, TreeLeft(n));
    }
    else {
        // Va a destra
        n->right = BstInsertRec(e, TreeRight(n));
    }
    return n;
}

int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

    Node* t = TreeCreateRoot(e + 15,
        TreeCreateRoot(e + 10,
            TreeCreateRoot(e + 3, NULL, NULL),
            TreeCreateRoot(e + 12, NULL, NULL)),
        TreeCreateRoot(e + 21, NULL, NULL));

    t = BstInsertRec(e + 22, t);
    Node *res = DeleteBstNode(t,5);
    TreeDelete(t);
    return 0;
}