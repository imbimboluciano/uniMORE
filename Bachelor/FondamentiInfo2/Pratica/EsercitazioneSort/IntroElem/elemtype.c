#include "elemtype.h"


String StringCopy(const String* e) {
	String res = { .size = e->size };
	res.data = malloc(res.size);
	memcpy(res.data, e->data, res.size);
	return res;
}

int StringCompare(const String* a, const String* b) { // comparazione tra stringhe simili al confronto standard
	for (size_t i = 0; i < a->size && i < b->size; i++) {
		if (a->data[i] < b->data[i]) {
			return -1;
		}
		else if (a->data[i] > b->data[i]) {
			return 1;
		}
	}

	if (a->size < b->size) {
		return -1;
	}
	else if (a->size < b->size) {
		return 1;
	}
	else {
		return 0;
	}
}

void Swap(String* a, String* b) {
	String tmp = *a;
	*a = *b;
	*b = tmp;
}


void StringDelete(String* e) {
	free(e->data);
}