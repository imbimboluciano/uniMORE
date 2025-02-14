#include "tree.h"
#include<stdlib.h>

Node* minValueNode(Node* node)
{
	Node* current = node;

	while (current && current->right != NULL)
		current = current->right;

	return current;
}


Node* DeleteBstNode(Node* n, const ElemType* key)
{
	//caso base
	if (TreeIsEmpty(n)) {
		return n;
	}

	if (ElemCompare(key, TreeGetRootValue(n)) < 0) {
		n->left = DeleteBstNode(TreeLeft(n), key);
	}else if (ElemCompare(key, TreeGetRootValue(n)) > 0) {
		n->right = DeleteBstNode(TreeRight(n), key);
	}else {
		// Nodo con un figlio o no figli
		if (TreeIsEmpty(TreeLeft(n))) {
			Node* temp = n->right;
			free(n);
			return temp;
		}
		else if (TreeIsEmpty(TreeRight(n))) {
			Node* temp = n->left;
			free(n);
			return temp;
		}

		// Nodo con due figli
		// Trova il predecessore più grande
		Node* temp = minValueNode(TreeLeft(n));
		
		n->value = temp->value;
		n->left = DeleteBstNode(TreeLeft(n), &temp->value);
	}

	return n;
}




/*Node* DeleteBstNode(Node * n, const ElemType * key) {
		
	if (TreeIsEmpty(n)) return NULL;

	Node* l = n, *next = NULL;
	Node* pl = NULL, *pr = NULL;

		while (ElemCompare(key, TreeGetRootValue(n)) != 0 && !TreeIsEmpty(n)){
			if (ElemCompare(key, TreeGetRootValue(n)) < 0) {
				pl = n;
				pr = TreeCreateEmpty();
				n = TreeLeft(n);
			}
			else {
				pl = TreeCreateEmpty();
				pr = n;
				n = TreeRight(n);
			}
		}

		if (!TreeIsEmpty(n)) {

			// Il nodo da eliminare è una foglia
			if (TreeIsLeaf(n)) {
				// Se e' la root ritorno un albero vuoto
				if (n == l) {
					free(pl);
					free(pr);
					return TreeCreateEmpty();
				}
				next = TreeCreateEmpty();
			}
			else {
				// Il nodo da eliminare ha un solo figlio
				if (TreeIsEmpty(TreeLeft(n))) {
					// Se e' la root ritorno il figlio
					if (n == l) {
						free(pl);
						free(pr);
						return TreeRight(n);
					}
					next = TreeRight(n);
				}
				else {
					if (TreeIsEmpty(TreeRight(n))) {
						// Se e' la root ritorno il figlio
						if (n == l) {
							free(pl);
							free(pr);
							return TreeLeft(n);
						}
						next = TreeLeft(n);
					}
					else {
						// Il nodo da eliminare ha due figli

						pr = TreeCreateEmpty();
						pl = n;

						next = TreeLeft(n);
						while (!TreeIsEmpty(TreeRight(next))) {
							pr = next;
							pl = TreeCreateEmpty();;
							next = TreeRight(next);
						}


						n->value = *TreeGetRootValue(next);
						if (!TreeIsEmpty(TreeLeft(next))) {
							next = TreeLeft(next);
						}
						else {
							next = TreeCreateEmpty();
						}
							
					}
				}

			}

			if (!TreeIsEmpty(pl)) {
				pl->left = next;
			}
				
			if (!TreeIsEmpty(pr)) {
				pr->right = next;
				
			}

		}
		
		return l;

}
*/
