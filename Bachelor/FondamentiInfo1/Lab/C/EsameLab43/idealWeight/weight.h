#pragma once
#include<stdlib.h>

enum formula { lorenz, berthean, keys };
extern double ideal_weight(int h, int age, char sex, enum formula f);