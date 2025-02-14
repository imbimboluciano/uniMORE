#include "rational.h"

int main(void) {
	struct rational* sum = malloc(sizeof(struct rational));
	struct rational f = { 1,3 };
	struct rational s = { 1,3 };

	rational_sum(sum, &f, &s);
	free(sum);

	return 0;
}