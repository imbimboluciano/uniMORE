#include "list.h"

extern Item* Sort(Item* i);

int main(void) {
    ElemType e1[] = { "Michele", "Federico", "Massimiliano", "Massimiliano", "Stefano" };
    size_t e1_size = sizeof(e1) / sizeof(ElemType);

    Item* list_a = ListCreateEmpty();
    for (size_t i = 0; i < e1_size; ++i) {
        list_a = ListInsertBack(list_a, e1 + i);
    }

    Item* res = Sort(list_a);
	return 0;
}