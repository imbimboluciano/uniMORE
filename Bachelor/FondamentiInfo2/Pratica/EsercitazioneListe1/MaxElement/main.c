#include "list.h"


extern const ElemType* MaxElement(const Item* i);

int main(void) {
    ElemType e1[] = { 3, 4, 2, 0, 45, 1, 3 };
    size_t e1_size = sizeof(e1) / sizeof(ElemType);

    Item* list_a = ListCreateEmpty();
    for (size_t i = 0; i < e1_size; ++i) {
        list_a = ListInsertBack(list_a, e1 + i);
    }

    ElemType* res = MaxElement(list_a);

    return 0;
}

