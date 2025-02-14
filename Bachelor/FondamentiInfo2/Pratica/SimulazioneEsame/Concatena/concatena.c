#include "list.h"
#include<stdlib.h>

Item* ConcatenaN(Item** v, size_t v_size) {
	if (v_size == 0) {
		return NULL;
	}
	int IsEmpty = 1;
	for (size_t k = 0; k < v_size; k++) {
		if (!ListIsEmpty(v[k])) {
			IsEmpty = 0;
			break;
		}
		else {
			IsEmpty = 1;
		}

	}
	if (IsEmpty == 1) {
		return NULL;
	}
	size_t i = 0;
	if (ListIsEmpty(v[0])) {
		i++;
	}
	
	Item* tmp = v[i];
	while (i < v_size - 1) {
		if (!ListIsEmpty(v[i]) ) {
			while (!ListIsEmpty(ListGetTail(v[i]))) {
				v[i] = ListGetTail(v[i]);
			}
			v[i]->next = v[i + 1];
		
			
		}
		else {
			v[i - 1]->next = v[i + 1];
		}
		
		i++;
	}

	return tmp;
	
}