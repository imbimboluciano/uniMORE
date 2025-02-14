#include "vettore.h"


void Push(struct vettore* v, int d) {
	v->size += 1;
	v->data = realloc(v->data, v->size * sizeof(int));
	v->data[v->size - 1] = d;
}

int Pop(struct vettore* v) {

	int p = v->data[0];

	for (int i = 0; i < (int)v->size - 1; i++) {
		v->data[i] = v->data[i + 1];
	}
	v->size -= 1;
	v->data = realloc(v->data, v->size * sizeof(int));

	return p;
}