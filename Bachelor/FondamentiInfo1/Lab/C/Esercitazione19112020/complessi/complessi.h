#pragma once

struct complesso {
	double re, im;
};

extern void prodotto_complesso(struct complesso* comp1, const struct complesso* comp2);