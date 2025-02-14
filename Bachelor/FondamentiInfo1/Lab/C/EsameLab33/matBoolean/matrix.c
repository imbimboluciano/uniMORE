#include "matrix.h"

struct bmatrix* mat_boolean(const struct matrix* m, double rhs, enum comparisons cmp) {
	if (m == NULL) return NULL;
	struct bmatrix* res = malloc(sizeof(struct bmatrix));
	res->cols = m->cols;
	res->rows = m->rows;
	res->data = calloc(res->cols * res->rows, sizeof(bool));

	for (size_t r = 0; r < res->rows; r++) {
		for (size_t c = 0; c < res->cols; c++) {
			switch (cmp)
			{
			case LT: if (m->data[r * m->cols + c] < rhs) res->data[r * res->cols + c] = true;
				   else  res->data[r * res->cols + c] = false;
				break;
			case LE: if (m->data[r * m->cols + c] <= rhs) res->data[r * res->cols + c] = true;
				   else  res->data[r * res->cols + c] = false;
				break;
			case EQ: if (m->data[r * m->cols + c] == rhs) res->data[r * res->cols + c] = true;
				   else  res->data[r * res->cols + c] = false;
				break;
			case NE: if (m->data[r * m->cols + c] != rhs) res->data[r * res->cols + c] = true;
				   else  res->data[r * res->cols + c] = false;
				break;
			case GE: if (m->data[r * m->cols + c] >= rhs) res->data[r * res->cols + c] = true;
				   else  res->data[r * res->cols + c] = false;
				break;
			case GT: if (m->data[r * m->cols + c] > rhs) res->data[r * res->cols + c] = true;
				   else  res->data[r * res->cols + c] = false;
				break;
			}
		}
	}

	return res;
}