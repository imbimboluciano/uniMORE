#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>


typedef struct {
    int codice;
    float peso;
    float prezzo;
} Gioiello;

extern Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size);
