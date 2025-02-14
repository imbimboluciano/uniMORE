#include "tree.h"


int ContaLivelli(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}

	int lheight = ContaLivelli(TreeLeft(t));
	int rheight = ContaLivelli(TreeRight(t));

	if (lheight > rheight) {
		return lheight + 1;
	}
	else {
		return rheight + 1;
	}
}
void PrintNodeLevel(const Node* t, int currentlevel, int level) {
	if (TreeIsEmpty(t)) {
		return;
	}

	if (currentlevel == level) {
		fprintf(stdout, "%d ", *TreeGetRootValue(t));
		return;
	}

	PrintNodeLevel(TreeLeft(t), currentlevel + 1, level);
	PrintNodeLevel(TreeRight(t), currentlevel + 1, level);
}
void LevelOrder(const Node* t) {
	int liv = ContaLivelli(t);
	for (int i = 0; i <= liv; i++) {  // non funziona del tutto
		PrintNodeLevel(t, 0, i);
	}
}

