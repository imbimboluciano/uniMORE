#include "list.h"

int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4 };

    Item *list = ListCreateEmpty();
    // Item *list = NULL;
    list = ListInsertHead(e + 0, list);
    list = ListInsertHead(e + 1, list);
    list = ListInsertHead(e + 2, list);
    list = ListInsertHead(e + 3, list);
    list = ListInsertHead(e + 4, list);

    {
        Item *tmp = list;
        while (!ListIsEmpty(tmp)) {
            // cose con tmp
            tmp = ListGetTail(tmp);
        }
    }
    {
        Item *tmp = list;
        while (tmp) {
            // cose con tmp
            tmp = tmp->next;
        }
    }
    {
        for (Item *tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)){
            // cose con tmp
        }
    }
    {
        for (Item *tmp = list; tmp; tmp = tmp->next) {
            // cose con tmp
        }
    }

    ListDelete(list);

    return 0;
}