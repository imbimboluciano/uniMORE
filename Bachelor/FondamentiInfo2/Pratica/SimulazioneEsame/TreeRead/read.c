#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include<stdlib.h>

Node* InsertTreeRead(FILE *f) {
	char tmp ;
	if (!feof(f)) {
		bool foglia = false;
		fscanf(f, "%c ", &tmp);
		if (tmp == '.') {
			foglia = true;
			fscanf(f, "%c ", &tmp);
		}
		Node* t = TreeCreateRoot(&tmp, NULL, NULL); 
		if (!foglia) {
			t->left = InsertTreeRead(f);
			t->right = InsertTreeRead(f);
		}
		return t;
	}
	return NULL;

}

Node* TreeRead(const char* filename) {
	if (filename == NULL) {
		return NULL;
	}

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	
	Node* res = InsertTreeRead(f);



	fclose(f);
	return res;
}