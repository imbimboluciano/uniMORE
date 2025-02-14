#pragma once
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<string.h>


typedef struct {
    unsigned int p; // Peso
    unsigned int a; // Altezza
    unsigned int l; // Limite
} Cartone;

extern void TorreCartoni(const Cartone* c, size_t n);
