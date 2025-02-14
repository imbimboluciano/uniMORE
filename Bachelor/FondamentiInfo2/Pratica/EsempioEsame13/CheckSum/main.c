#include "tree.h"

extern bool CheckSumN(const Node* t, int n);

int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };

    Node* t = TreeCreateRoot(e + 4,TreeCreateRoot(e + 2,TreeCreateRoot(e + 1, NULL, NULL), NULL),TreeCreateRoot(e + 5, NULL, NULL));

    bool res = CheckSumN(t,5);
    TreeDelete(t);
    return 0;
}