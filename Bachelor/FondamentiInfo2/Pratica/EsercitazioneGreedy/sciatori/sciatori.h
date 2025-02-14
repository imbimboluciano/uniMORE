#pragma once
#include<stdlib.h>
#include<stdint.h>
#include<math.h>
#include<float.h>



typedef struct {
    double a;
    double l;
} Sciatore;

extern Sciatore* Accoppia(double* altezze, double* lunghezze, size_t v_size);
