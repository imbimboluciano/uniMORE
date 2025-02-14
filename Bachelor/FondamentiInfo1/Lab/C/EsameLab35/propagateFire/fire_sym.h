#pragma once
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
struct forest {
	size_t rows, cols;
	char* data;
};

extern void propagate_fire(const struct forest* f);