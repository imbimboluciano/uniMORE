#include "minheap.h"

void HeapMinMoveDownRecRec(Heap* h, int i, bool done) {
    if (done == true) {
        return;
    }
    int l, r, smallest = i;

    done = true;
    l = HeapLeft(i);
    r = HeapRight(i);

    if ((l < (int)h->size) && ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, smallest)) < 0) {
        smallest = l;
    }

    if ((r < (int)h->size) && ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, smallest)) < 0) {
        smallest = r;
    }

    if (smallest != i) {
        ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, smallest));
        i = smallest;
        done = false;
    }

    HeapMinMoveDownRecRec(h, i, done);
}



void HeapMinMoveDownRec(Heap* h, int i) {
    bool done = false;
    HeapMinMoveDownRecRec(h, i, done);
    
}

