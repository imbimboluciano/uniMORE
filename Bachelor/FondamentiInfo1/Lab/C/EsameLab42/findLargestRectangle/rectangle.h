#pragma once
#include<stdlib.h>
#include<math.h>

struct point {
    int x, y;
};
struct rect {
    struct point a, b;
};
extern int find_largest(const struct rect* r, size_t n);