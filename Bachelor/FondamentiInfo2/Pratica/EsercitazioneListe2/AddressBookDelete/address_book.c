#include "list.h"
#include<string.h>
#include<stdlib.h>


Item* Delete(Item* i, const char* name) {
	
	if (ListIsEmpty(i)) return i;

	Item* box = i;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		ElemType* testa = ListGetHeadValue(tmp);
		if (strcmp(testa->name, name) == 0) {
			ElemDelete(testa);
			if (tmp == i) {
				free(tmp);
				return box->next;
			}
			else {
				box->next = tmp->next;
			}
			
			free(tmp);

			break;
		}
		
		box = tmp;
	}

	return i;
	
}