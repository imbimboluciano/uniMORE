#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct nonogram {
    size_t n;
    char* schema;
};


extern bool nonogram_load(struct nonogram* ng, const char* filename);