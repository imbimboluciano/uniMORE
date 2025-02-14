#include "sparse_matrix.h"

double sm_get(struct sparse_matrix* m, uint32_t row, uint32_t col) {
	if (m == NULL || row >= m->rows || col >= m->cols) return 0;
	for (int i = 0; i < (int)m->nnz; i++) {
		if (row == m->rowidxs[i] && col == m->colidxs[i]) {
			return m->data[i];
		}
	}
	return 0;

}
