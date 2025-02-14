#pragma once
#include<stdlib.h>
#include<stdio.h>

struct Articolo {
    char nome[11];
    int prezzo;
};


extern void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum);