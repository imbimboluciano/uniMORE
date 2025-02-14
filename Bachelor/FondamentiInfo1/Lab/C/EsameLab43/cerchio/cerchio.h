#pragma once 
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>


struct punto {
	double x, y;
};
struct cerchio {
	double x, y, r;
};

extern bool nel_cerchio(const struct punto* p, const struct cerchio* c);