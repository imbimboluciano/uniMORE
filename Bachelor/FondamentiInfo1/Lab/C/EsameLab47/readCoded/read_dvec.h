#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>

struct dvec {
    size_t n;
    double* d;
};

extern struct dvec* read_dvec_comp(const char* filename);