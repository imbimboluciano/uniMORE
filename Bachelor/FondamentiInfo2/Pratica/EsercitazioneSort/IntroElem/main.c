#include "elemtype.h"
typedef struct {
	size_t capacity;
	size_t size;
	String* data;
} Vector;


void Pushback(Vector* v,const String *e) {
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->data = realloc(v->data, sizeof(int) * v->capacity);
	}
	v->data[v->size] = StringCopy(e);
	(v->size)++;
}



void NaiveSort(Vector* v) {
	for (size_t i = 0; i < v->size; i++) {
		size_t minpos = i;
		for (size_t j = i + 1; j < v->size; j++) {
			if (StringCompare(v->data + j, v->data + minpos) < 0) {
				minpos = j;
			}
		}
		if (i != minpos) {
			//Swap(&v->data[i], &v->data[minpos]);
			Swap(v->data + i, v->data + minpos);
		}
	}

}

int main(void) {
	Vector v = { .capacity = 1, .size = 0, .data = malloc(sizeof(String)) };
	String arr[] = { {6,"parola"},{5,"mamma"},{5,"gatto"},{7,"gattone"} };
	for (size_t i = 0; i < 20; i++) {
		Pushback(&v, &arr[i]);
	}

	NaiveSort(&v);

	for (size_t i = 0; i < v.size; i++) {
		StringDelete(v.data + i);
	}

	free(v.data);

	return 0;
}